class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    
    ll dp[1002][1002] = {0};
    
    int helper(int i, int j) {
        if (i < j) return 0;
        if (j == 0) return 1;
        if (dp[i][j]) return dp[i][j];
        return dp[i][j] = (helper(i-1, j) + helper(i-1, j-1)) % mod;
    }
    
    
    int numOfWays(vector<int>& nums) {
        return static_cast<int> (dfs(nums) - 1);
    }
    
    ll dfs(vector<int>& nums) {
        int i = 0, j = nums.size()-1;
        if (i >= j) return 1;
        
        vector<int> v[2];
        
        for (int k = i+1; k <= j; ++k) {
            int t = nums[k] < nums[i] ? 1 : 0;
            v[t].push_back(nums[k]);
        }
        
        ll a = dfs(v[0]), b = dfs(v[1]);
        return (a*b % mod) * helper(v[0].size()+v[1].size(), v[1].size()) % mod;
    }
};
