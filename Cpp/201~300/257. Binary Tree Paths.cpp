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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        dfs(root, "", res);
        return res;
    }
    
private:    
    void dfs(TreeNode* root, string path, vector<string> &res) {
        path +=  to_string(root->val);
        if (root->left == nullptr && root->right == nullptr) {
            res.push_back(path);
            return;
        }
        path += "->";
        if (root->left) dfs(root->left, path, res);
        if (root->right) dfs(root->right, path, res);
    }
};