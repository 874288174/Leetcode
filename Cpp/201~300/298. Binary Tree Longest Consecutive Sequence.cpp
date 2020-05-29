class Solution {
public:
    int longestConsecutive(TreeNode* root) {
        if (!root) return 0;
        dfs(root, root->val, 0);
        return res;
    }
    
private:
    int res = 0;
    void dfs(TreeNode *root, int pre, int len) {
        if (!root) return;
        res = max(res, len = (root->val == pre + 1) ? len+1 : 1);
        dfs(root->left, root->val, len);
        dfs(root->right, root->val, len);
    }
};