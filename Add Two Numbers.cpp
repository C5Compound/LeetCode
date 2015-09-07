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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (l1 == NULL) {
            return l2;
        }
        if (l2 == NULL) {
            return l1;
        }
        int carry = 0;
        ListNode it(1024), *p = &it;
        while (l1 != NULL && l2 != NULL) {
            int tmp = l1->val + l2->val + carry;
            p->next = new ListNode(tmp % 10);
            carry = tmp / 10;
            l1 = l1->next;
            l2 = l2->next;
            p = p->next;
        }
        l1 = l1 == NULL ? l2 : l1;
        while (l1 != NULL) {
            int tmp = l1->val + carry;
            p->next = new ListNode(tmp % 10);
            carry = tmp / 10;
            l1 = l1->next;
            p = p->next;
        }
        if (carry > 0) {
            p->next = new ListNode(carry);
        }
        return it.next;
    }
};