class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int a = n / 3, b = n % 3;
        if (b == 0) return pow(3, a);
        else if (b == 1) return pow(3, a - 1) * 4;
        else return pow(3, a) * 2;
    }
};

class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n-1;
        vector<int> dp(n+1, 0);
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for (int i = 4; i <= n; ++i) {
            for (int j = 2; j < i; ++j) {
                dp[i] = max(dp[i], j * dp[i-j]);
            }
        }
        return dp[n];
    }
};