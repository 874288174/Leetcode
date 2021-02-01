class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size(), p = 0;
        vector<vector<vector<int>>> dp(2, vector<vector<int>> (n, vector<int>(n, -1)));
        dp[0][0][0] = grid[0][0]; 
        
        const int maxK = 2 * (n - 1); 
        
        for (int k = 1; k <= maxK; k++) {
            auto &pre = dp[p], &cur = dp[p^1];
            for (auto &v : cur) for (auto &i : v) i = -1;
        
            for (int i = 0; i < n && i <= k; i++) {
                if (k - i >= n || grid[i][k-i] < 0) continue;
                for (int j = 0; j < n && j <= k; j++) {
                    if (k - j >= n || grid[j][k - j] < 0) continue;
                    
                    int cherries = pre[i][j];
                    if (i > 0) cherries = std::max(cherries, pre[i - 1][j]);
                    if (j > 0) cherries = std::max(cherries, pre[i][j - 1]);
                    if (i > 0 && j > 0) cherries = std::max(cherries, pre[i - 1][j - 1]);
                    
                    
                    if (cherries < 0) continue;
                    cherries += grid[i][k - i] + (i == j ? 0 : grid[j][k - j]);
                    cur[i][j] = cherries;
                }
            }
            p ^= 1;
        }
        
        return std::max(dp[p][n-1][n-1], 0); 
    }
};