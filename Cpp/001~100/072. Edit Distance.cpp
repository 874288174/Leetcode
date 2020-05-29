class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<vector<int>> dp(2, vector<int>(n+1));
        int k = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0) dp[k][j] = j;
                else if (j == 0) dp[k][j] = i;
                else if (word1[i-1] == word2[j-1]) dp[k][j] = dp[k^1][j-1];
                else  dp[k][j] = 1 + min(dp[k^1][j-1], 
                                         min(dp[k][j-1], dp[k^1][j]));
            }
            k ^= 1;
        }
        return dp[k^1][n];
    }
};