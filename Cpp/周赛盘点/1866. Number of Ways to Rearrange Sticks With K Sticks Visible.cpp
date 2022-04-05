class Solution {
private:
    static constexpr int mod = 1000000007;
    using ll = long long;
public:
/*
tip 考虑最后一根木棍是否可以被看到
    可以看到 dp[i-1][j] 不可以看到 (i-1)*dp[i-1][j-1]
*/
    int rearrangeSticks(int n, int k) {
        vector<ll> dp(n+1);
        dp[1] = 1;
        for (int i = 2;i <= n; i++) {
            for (int j = k;j >= 1;j--) {
                dp[j] = ((i-1)*dp[j] + dp[j-1]) % mod;
            }
        }
        return static_cast<int> (dp[k]);
    }
};