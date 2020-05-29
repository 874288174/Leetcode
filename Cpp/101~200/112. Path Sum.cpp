class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;
        return dfs(root, 0, sum);
    }
private: 
    bool dfs(TreeNode *t, int cur, int &sum) {
        if (!t) return false;
        cur += t->val;
        if (!(t->left) && !(t->right)) return cur == sum;
        return dfs(t->left, cur, sum) || dfs(t->right, cur, sum);
    }
};