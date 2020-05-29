class Solution {
public:
    void flatten(TreeNode* root) {
        while (root) { 
            TreeNode *p = root->left;
            if (p) {
                while (p->right) p = p->right;
                p->right = root->right;
                root->right = root->left;
                root->left = nullptr;
            }
            root = root->right;
        }
    } 
};


//////////////////////////////////////////////////////


class Solution {
public:
    void flatten(TreeNode* root) {
        flatten(root, nullptr);
    } 
    TreeNode* flatten(TreeNode *root, TreeNode *tail) {
        if (root == nullptr) return tail;
        root->right = flatten(root->left, flatten(root->right, tail));
        root->left = nullptr;
        return root;
    }
};