class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<long long>> dp(2, vector<long long>(k+1));
        dp[0][0] = 1;
        int p = 0;
        for(int i = 1; i <= n; ++i){
            auto &pre = dp[p], &cur = dp[p^1];
            cur[0] = 1;
            for(int j = 1; j <= k; ++j){
                cur[j] = (cur[j-1] - (j >= i ? pre[j-i]:0) + pre[j] + mod) % mod;
            }
            p ^= 1;
        }
        return static_cast<int> (dp[p][k]);
    }
private:
    const long long mod = 1e9 + 7;
};