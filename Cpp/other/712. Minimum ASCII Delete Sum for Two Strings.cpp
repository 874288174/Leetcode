class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        int total = accumulate(s1.begin(), s1.end(), 0)     
                    + accumulate(s2.begin(), s2.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j){
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i-1][j-1] + s2[j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return total - 2 * dp[n][m];
    }
};