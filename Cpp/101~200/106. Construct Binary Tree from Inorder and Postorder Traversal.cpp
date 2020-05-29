class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(postorder.size()-1, 0, inorder.size()-1, postorder, inorder);
    }
    
    TreeNode *build(int postr, int inl, int inr, vector<int>& postorder, vector<int>& inorder) {
        if(inl > inr) return nullptr;
        int i = inl;
        while (inorder[i] != postorder[postr]) i++;
        TreeNode *t = new TreeNode(inorder[i]);
        t->left = build(i-1-inr+postr, inl, i-1, postorder, inorder);
        t->right = build(postr-1, i+1, inr, postorder, inorder);
        return t;
    }
};