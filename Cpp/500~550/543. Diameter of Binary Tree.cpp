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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        f(root, res);
        return res;
    }

private:
    int f(TreeNode *root, int &res) {
        if (!root) return 0;
        int L = f(root->left, res);
        int R = f(root->right, res);
        res = max(res, L+R);
        return max(L, R) + 1;
    }
};