class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(2, vector<int> (m+1, n+m));
        int p = 0;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i || !j) dp[p][j] = i + j;
                else {
                    dp[p][j] = dp[p^1][j-1] + (s[i-1] == t[j-1] ? 0 : 2);
                    dp[p][j] = min(dp[p][j], 1 + min(dp[p^1][j], dp[p][j-1]));
                }
            }
            p ^= 1;
        }
        return dp[p^1][m];
    }
};