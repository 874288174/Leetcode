class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
    
private:
    int dfs(TreeNode *t, int sum) {
        if (!t) return 0;
        sum = sum*10+t->val;
        if (t->left == nullptr && t->right == nullptr) return sum;
        return dfs(t->left, sum)+dfs(t->right, sum);
    }
};