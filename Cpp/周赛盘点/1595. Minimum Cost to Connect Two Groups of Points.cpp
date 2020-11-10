class Solution {
public:
    int connectTwoGroups(vector<vector<int>>& cost) {
        int n = cost.size(), m = cost[0].size(), k = 0;
        vector<vector<int>> dp(2, vector<int>(1 << m, 1e9));
        dp[0][0] = 0;
        
        for(int i = 0; i < n; ++i) {
            auto &pre = dp[k], &cur = dp[k^1];
            for (int mask = 0; mask < 1<<m; ++mask) {
                cur[mask] = 1e9;
                for (int j = 0; j < m; ++j) {
                    cur[mask] = min({cur[mask], cost[i][j] + pre[mask & ~(1 << j)], cost[i][j] + cur[mask & ~(1 << j)]});
                }
            }
            k ^= 1;
        }
        return dp[k].back();
    }
};