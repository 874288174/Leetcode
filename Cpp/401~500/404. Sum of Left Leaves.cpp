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
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        dfs(root, res, false);
        return res;
    }
private:
    void dfs(TreeNode* root, int &res, bool type) {
        if (root == nullptr) return;
        if (!root->left && !root->right && type) {
            res += root->val;
        }
        dfs(root->left, res, true);
        dfs(root->right, res, false);
    }
};