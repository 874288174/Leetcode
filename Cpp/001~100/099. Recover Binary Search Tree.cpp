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
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(p->val, q->val);    
    }
    
private:
    TreeNode *p = nullptr, *q = nullptr, *prev = nullptr;  
    void inorder(TreeNode *root) {
        stack<TreeNode*> stk;
        while (!stk.empty() || root) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop(); 
            if (prev && root->val < prev->val) {
                if (!p)  p = prev;
                q = root;
            }
            prev = root;
            root = root->right;   
        }
    }
};

