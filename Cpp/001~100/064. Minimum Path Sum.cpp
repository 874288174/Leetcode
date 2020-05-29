class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int res = 0;
        if (grid.empty()) return res;
        int n = grid.size(), m = grid[0].size();
        vector<int> f(m+1, INT_MAX);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (i == 1 && j == 1) f[i] = grid[i-1][j-1];
                else f[j] = min(f[j], f[j-1]) + grid[i-1][j-1];
            }
        }
        return f[m];
    }
};


////////////////////////////////////////////
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int res = 0;
        if (grid.empty()) return res;
        int n = grid.size(), m = grid[0].size();
        vector<int> f = grid[0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0) f[j] += (j == 0 ? 0: f[j-1]);
                else if (j == 0) f[j] += grid[i][j];
                else f[j] = min(f[j], f[j-1]) + grid[i][j];
            }
        }
        return f[m-1];
    }
};