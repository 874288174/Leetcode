class Solution {
public:
    int minimumTimeRequired(vector<int>& jobs, int k) {
        int n = jobs.size(), m = 1<<n;
        vector<vector<int>> dp(1<<n, vector<int> (k+1, INT_MAX));
        vector<int> cost(m, 0);
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) cost[i] += jobs[j];
            }
            dp[i][1] = cost[i];
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < k; ++j) {
                if (dp[i][j] == INT_MAX) continue;
                int other = m-1-i;
                for (int a = other; a != 0; a = (a-1)&other) {
                    dp[a|i][j+1] = min(dp[a|i][j+1], max(dp[i][j], cost[a]));
                }
            }            
        }
        return dp[m-1][k];
    }
};