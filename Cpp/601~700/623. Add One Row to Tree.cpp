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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        auto dummp = new TreeNode(-1);
        dummp->left = root;
        dfs(dummp, v, d);
        return dummp->left;
    }
    
private:
    void dfs(TreeNode* root, int v, int d) {
        if (!root) return;
        if (--d) {
           dfs(root->left, v, d);
           dfs(root->right, v, d);
        }
        else {
            auto l = root->left, r = root->right;
            root->left = new TreeNode(v);
            root->left->left = l;
            root->right = new TreeNode(v);
            root->right->right = r;
        }
    }
};