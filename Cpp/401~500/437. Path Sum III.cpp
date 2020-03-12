class Solution {
public:
    int pathSum(TreeNode* root, int sum) {    
        return dfs(root, sum, 0);
    }
        
private: 
    unordered_map<int, int> mp;
    
    int dfs(TreeNode *root, int sum, int pre) {
        if (!root) return 0;
        int cur = root->val + pre;
        int res = (cur == sum) + (mp.count(cur - sum) ? mp[cur - sum] : 0);
        mp[cur]++;
        res += dfs(root->left, sum, cur) + dfs(root->right, sum, cur);
        mp[cur]--;
        return res;
    }
};