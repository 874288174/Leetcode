class Solution {
public:
    int numDistinct(string s, string t) {
      int m = s.length(), n = t.length();
      vector<vector<long long>> dp(2, vector<long long>(n + 1, 0)); 
      dp[0][0] = dp[1][0] = 1;
      int k = 0;
      for (int i = 1; i <= m; i++) { 
          for (int j = 1; j <= n; j++) {
              dp[k][j] = dp[k^1][j] + (s[i-1] == t[j-1] ? dp[k^1][j-1] : 0);        
          }
          k ^= 1;
      }
      return dp[k^1][n];
    }
}