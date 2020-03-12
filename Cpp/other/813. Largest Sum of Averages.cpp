class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        //dp(i, k)  第i位 划分k 的max_sum
        //dp(i, k) = dp(j, k-1) + sum(i, j) / (i-j)
        int n = A.size();
        vector<vector<double>> dp(n+1, vector<double> (K, 0));
        vector<double> sum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            sum[i] = sum[i-1] + A[i-1];
        }
        for (int k = 0; k < K; ++k) {
           for (int i = 1; i <= n; ++i) {
                if (k == 0) dp[i][k] = sum[i] / i;
                else for (int j = 0; j < i; ++j) {
                    dp[i][k] = max(dp[i][k], dp[j][k-1] + (sum[i] - sum[j]) / (i-j)); 
                }
            }
        }
        return dp[n][K-1];
    }
};