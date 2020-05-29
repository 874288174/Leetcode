class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        int n = matrix.size(), m = matrix[0].size();
        dp.resize(n+1, vector<int>(m+1, 0));
        for (int r = 0; r < n; r++) {
           for (int c = 0; c < m; c++) {
              dp[r + 1][c + 1] = dp[r + 1][c] + dp[r][c + 1] 
                                 + matrix[r][c] - dp[r][c];
            }  
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return dp[row2 + 1][col2 + 1] - dp[row1][col2 + 1] 
               - dp[row2 + 1][col1] + dp[row1][col1];
    }
private:
    vector<vector<int>> dp;
};
