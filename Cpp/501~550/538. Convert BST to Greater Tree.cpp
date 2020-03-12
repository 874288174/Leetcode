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
    TreeNode* convertBST(TreeNode* root) {
        if (!root) return nullptr;
        stack<TreeNode*> stk;
        TreeNode *p = root;
        int sum = 0;
        while (!stk.empty() || p) {
            while (p) {
                stk.push(p);
                p = p->right;
            }
            p = stk.top();
            stk.pop();
            // visit
            sum = p->val = p->val + sum;
            p = p->left;
        }
        return root;
    }
};