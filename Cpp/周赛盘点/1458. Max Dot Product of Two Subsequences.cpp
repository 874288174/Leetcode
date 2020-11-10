class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = B.size();
        vector<vector<int>> dp(2, vector<int>(m));
        int k = 0;
        for (int i = 0; i < n; ++i) {
            auto &pre = dp[k], &cur = dp[k^1];
            for (int j = 0; j < m; ++j) {
                cur[j] = A[i] * B[j];
                if (i && j) cur[j] += max(pre[j - 1], 0);
                if (i) cur[j] = max(cur[j], pre[j]);
                if (j) cur[j] = max(cur[j], cur[j - 1]);
            }
            k ^= 1;
        }
        return dp[k][m - 1];
    }
};


