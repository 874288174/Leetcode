class Solution {
public:
    int maxPathSum(TreeNode *root) {
        int res = INT_MIN;
        maxToRoot(root, res);
        return res;
    }
    
private:
    int maxToRoot(TreeNode *root, int &res) {
        if (!root) return 0;
        int l = maxToRoot(root->left, res);
        int r = maxToRoot(root->right, res);
        if (l < 0) l = 0;
        if (r < 0) r = 0;
        res = max(res, l + r + root->val);
        return root->val += max(l, r);
    }
};