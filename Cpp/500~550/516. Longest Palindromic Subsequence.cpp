class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; --i) {
            dp[i][i] = 1;
            for (int j = i + 1; j < n; ++j) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};

/*
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> g(n, vector<int>(n, 1));
        for (int len = 1; len < n; len++) {
            for (int i = 0, j = len; j < n; i++, j++) {
                g[i][j] = s[i] != s[j] ?  max(g[i+1][j], g[i][j-1]) : (2 + (j-i > 1 ? g[i+1][j-1] : 0));
            }
        }
        return g[0][n-1];
    }
};
*/