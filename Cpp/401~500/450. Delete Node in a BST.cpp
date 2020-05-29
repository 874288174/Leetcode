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
    TreeNode *deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;
        if (root->val == key) {
            TreeNode *t = root->right;
            if (t == nullptr) {
                return root->left;
            }
            while (t->left) t = t->left;
            root->val = t->val;
            root->right = deleteNode(root->right, t->val);
        }
        else if (root->val > key && root->left)
           root->left = deleteNode(root->left, key);
        else if (root->val < key && root->right)
            root->right = deleteNode(root->right, key);
        return root;
    }
};