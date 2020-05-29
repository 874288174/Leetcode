class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LONG_MIN, LONG_MAX);        
    }
    
    bool isValidBST(TreeNode* root, long long Min, long long Max) {
        if(root == nullptr) return true;
        return root->val < Max && root->val > Min
            && isValidBST(root->left, Min, root->val) 
            && isValidBST(root->right, root->val, Max);
    }
};