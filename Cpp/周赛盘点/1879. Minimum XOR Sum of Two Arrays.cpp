class Solution {
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = 1<<n;
        vector<int> dp(m, 2e9);
        dp[0] = 0;
        
        for (int i = 0; i < m; ++i) {
            if (dp[i] >= 2e9) continue;
            int cnt = __builtin_popcount(i);
            for (int j = 0; j < n; ++j) {
                if ((i & (1<<j)) == 0) {
                    dp[i | (1<<j)] = min(dp[i | (1<<j)], dp[i] + (nums1[cnt] ^ nums2[j]));
                }
            }
        }
        return dp.back();
    }
};
