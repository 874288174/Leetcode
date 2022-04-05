class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(1 << n, 0);
        vector<vector<int>> g(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = __gcd(nums[i], nums[j]);
        
        for (int state = 0; state < (1 << n); ++state) {
            int cnt = __builtin_popcount(state);
            if (cnt & 1) continue;
            int now = cnt / 2 + 1;
            for (int i = 0; i < n; ++i)
                for (int j = i + 1; j < n; ++j) {
                    if ((state & (1 << i)) || (state & (1 << j))) continue;
                    int nxt = state | (1 << i) | (1 << j);
                    dp[nxt] = max(dp[nxt], dp[state] + g[i][j] * now);
                }
        }
        return dp.back();
    }
};
