class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(2, vector<int> (m+1, 0));
        int p = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {   
                dp[p][j] = dp[p^1][j-1] + (s[i-1] == t[j-1] ? 1 : 0);
                dp[p][j] = max(dp[p][j], max(dp[p^1][j], dp[p][j-1]));
            }
            p ^= 1;
        }
        return dp[p^1][m];
    }
};