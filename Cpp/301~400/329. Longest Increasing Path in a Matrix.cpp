
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));      
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ret = max(ret, dfs(i, j, n, m, matrix, dp));
            }
        }
        return ret;
    }
private:
    const vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int dfs(int x, int y, int n, int m, vector<vector<int>>& matrix, vector<vector<int>> &dp) {
        if (dp[x][y]) return dp[x][y];
        for (auto [dx, dy] : dirs) {
            int xx = x + dx, yy = y + dy;
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (matrix[xx][yy] <= matrix[x][y]) continue;
            dp[x][y] = max(dp[x][y], dfs(xx, yy, n, m, matrix, dp));
        }
        return ++dp[x][y];
    }
};
