
/*
 *
 * dp[i]表示此次操作娶到第i位
 * dp[i] = sum(stones[j], j = 0 .. i) - max(dp[j], j = i+1...n)
 * 其中max操作可以用ans倒叙更新
 */

class Solution {
public:
    using ll = long long;
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<ll> s(n + 1);
        for (int i = 1; i <= n; ++i)
            s[i] = s[i - 1] + stones[i - 1];
        vector<ll> dp(n + 1);
        ll ans = dp[n] = s[n];
        for (int i = n - 1; i > 1; --i) {
            dp[i] = s[i] - ans;
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

