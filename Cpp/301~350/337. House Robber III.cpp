class Solution {
public:
    int rob(TreeNode* root) {
        int l, r;
        return tryRob(root, l, r);
    }
    
private:
    int tryRob(TreeNode *root, int &l, int &r) {  // l为左子树最大值（不考虑父亲节点偷不偷）
        if (!root) return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = tryRob(root->left, ll, lr);
        r = tryRob(root->right, rl, rr);
        return max(root->val + ll + lr + rl + rr, l + r);
    }
};