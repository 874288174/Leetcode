class Solution {
public:
    int numWays(int steps, int arrLen) {
        int n = min(arrLen, steps);
        vector<long long> dp(n, 0);
        dp[0] = 1;
        while (steps--) {
            int pre = 0;
            for (int i = 0; i < n; ++i) {
                long long temp = dp[i];
                dp[i] += pre + (i == n-1 ? 0 : dp[i+1]);
                dp[i] %= 1000000007;
                pre = temp;
            }
        }
        return dp[0];
    }
};