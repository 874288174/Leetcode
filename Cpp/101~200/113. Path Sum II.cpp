class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(root, sum, cur, res);
        return res;
    }
private:
    void dfs(TreeNode* root, int sum, vector<int> &cur,vector<vector<int>> &res) {
        if (root == nullptr) return;
        cur.push_back(root->val);
        if (root->left == nullptr && root->right == nullptr && sum == root->val)  
            res.push_back(cur); 
        dfs(root->left, sum - root->val, cur, res);
        dfs(root->right, sum - root->val, cur, res);
        cur.pop_back();
    }
};