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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        TreeNode *t;
        while (!que.empty()) {
            t = que.front();
            que.pop();
            if (t->right) que.push(t->right);
            if (t->left) que.push(t->left);
        }
        return t->val;
    }
};