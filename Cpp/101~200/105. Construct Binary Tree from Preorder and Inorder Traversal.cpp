class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(0, 0, preorder.size()-1, preorder, inorder);
    }
    
    TreeNode *build(int prel, int inl, int inr, vector<int>& preorder, vector<int>& inorder) {
        if(inl > inr) return nullptr;
        int i = inl;
        while (inorder[i] != preorder[prel]) i++;
        TreeNode *t = new TreeNode(inorder[i]);
        t->left = build(prel+1, inl, i-1, preorder, inorder);
        t->right = build(prel+i+1-inl, i+1, inr, preorder, inorder);
        return t;
    }
};