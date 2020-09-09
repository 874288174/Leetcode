class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    
    ll dp[1002][1002] = {0};
    
    int helper(int i, int j) {
        if (i == 0 && j == 0) return 0;
        if (i == 0 || j == 0) return 1;
        if (dp[i][j]) return dp[i][j];
        return dp[i][j] = (helper(i-1, j) + helper(i, j-1)) % mod;
    }
    
    
    int numOfWays(vector<int>& nums) {
        return static_cast<int> (dfs(nums) - 1);
    }
    
    ll dfs(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        
        if (i >= j) return 1;
        vector<int> v0, v1;
        
        for (int k = i+1; k <= j; ++k) {
            if (nums[k] > nums[i]) v0.push_back(nums[k]);
            else v1.push_back(nums[k]);
        }
        
        ll a = dfs(v0), b = dfs(v1);
        return (a*b % mod) * helper(v0.size(), v1.size()) % mod;
    }
};