class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size(), res = 0;
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (A[i-1] == B[j-1]) {
                    res = max(res, dp[i][j] = dp[i-1][j-1] + 1);
                }
            }
        }
        return res;
    }
};