/**
 *  直接用最小堆或者用最小堆模拟败者树
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> lists) {
        // 用最小堆模拟败者树
        auto f = [&](const int x, const int y)->bool{return lists[x]->val > lists[y]->val; };
        priority_queue<int, vector<int>, decltype(f)> Q(f);
        ListNode node(1024), *p = &node;
        int k = lists.size();
        // 初始化败者树
        for (int i = 0; i < k; ++i) {
            if (lists[i] == NULL) {
                continue;
            }
            Q.push(i);
        }
        while (!Q.empty()) {
            int i = Q.top();
            Q.pop();
            p->next = lists[i];
            p = p->next;
            lists[i] = lists[i]->next;
            if (lists[i] != NULL) {
                Q.push(i);
            }
        }
        return node.next;
    }
};

class Solution {
public:
    // 败者树调整函数
    void ajustLosers(int exnode[], int leaf[], int k, int i) {
        int p = (i + k) >> 1;
        while (p > 0) {
            if (exnode[p] == -1) {
                exnode[p] = i;
                return;
            }
            if (leaf[exnode[p]] < leaf[i]) {
                swap(exnode[p], i);
            }
            p >>= 1;
        }
        exnode[0] = i;
    }
    // 败者树建立函数
    void LoserTree(int exnode[], int leaf[], int k) {
        fill_n(exnode, k, -1);
        for (int i = 0; i < k; ++i) {
            ajustLosers(exnode, leaf, k, i);
        }
    }
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        if (lists.empty()) {
            return NULL;
        }
        ListNode node(1024), *p = &node;
        int k = lists.size();
        int exnode[2 * k], *leaf = exnode + k;
        // 初始化败者树
        for (int i = 0; i < k; ++i) {
            leaf[i] = lists[i] != NULL ? lists[i]->val : INT_MAX;
        }
        LoserTree(exnode, leaf, k);
        while (true) {
            int i = exnode[0];
            if (leaf[i] == INT_MAX) {
                break;
            }
            p->next = lists[i];
            p = p->next;
            lists[i] = lists[i]->next;
            leaf[i] = lists[i] != NULL ? lists[i]->val : INT_MAX;
            ajustLosers(exnode, leaf, k, i);
        }
        return node.next;
    }
};