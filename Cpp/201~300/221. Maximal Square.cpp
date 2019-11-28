class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<vector<int>> dp(2, vector<int>(m, 0));
        int k = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i == 0 && matrix[i][j] == '1') {
                    dp[k][j] = res = 1;
                }
                else if (matrix[i][j] == '0') dp[k][j] = 0;
                else if (j == 0) dp[k][j] = 1;
                else dp[k][j] = min(min(dp[k][j-1], dp[k^1][j]), dp[k^1][j-1])+1;
                res = max(res, dp[k][j]);
            }
            k ^= 1;
        }
        return res*res;
    }
};