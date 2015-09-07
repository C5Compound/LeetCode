class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> re;
        if (root == NULL) {
            return re;
        }
        deque<TreeNode*> Q;
        Q.push_back(root);
        int currentfloor = 1, turn = 1;
        vector<int> v;
        for (int i = 1; i <= currentfloor; ++i) {
            if (turn) {
                TreeNode *r = Q.front();
                Q.pop_front();
                v.push_back(r->val);
                if (r->left != NULL) {
                    Q.push_back(r->left);
                }
                if (r->right != NULL) {
                    Q.push_back(r->right);
                }
            } else {
                TreeNode *r = Q.back();
                Q.pop_back();
                v.push_back(r->val);
                if (r->right != NULL) {
                    Q.push_front(r->right);
                }
                if (r->left != NULL) {
                    Q.push_front(r->left);
                }
            }
            if (i == currentfloor) {
                re.push_back(v);
                v.clear();
                i = 0;
                turn = 1 - turn;
                currentfloor = Q.size();
            }
        }
        return re;
    }
};