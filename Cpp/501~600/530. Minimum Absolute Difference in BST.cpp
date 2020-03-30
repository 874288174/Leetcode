/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* p) {
        int pre, res = INT_MAX;
        bool isFirst = true;
        stack<TreeNode*> stk;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            if (isFirst) {
                pre = p->val;
                isFirst = false;
            }
            else {
                res = min(res, p->val - pre);
                pre = p->val;
            }
            p = p->right;
        }
        return res;
    }
};