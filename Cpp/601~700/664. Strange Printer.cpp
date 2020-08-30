class Solution {
public:
    int strangePrinter(string t) {
        if (t.empty()) return 0;
        string s;
        for (auto c : t) {
            if (s.empty() || c != s.back()) s += c;
        } 
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, s.size()-1);
    }
    
private:
    int dp[100][100];
    
    int dfs(string &s, int l, int r) {
        if (l > r) return 0;
        if (dp[l][r] >= 0) return dp[l][r];

        dp[l][r] = dfs(s, l, r-1) + 1;
        for (int i = l; i < r; ++i){
            if (s[i] == s[r]){
                dp[l][r] = min(dp[l][r], dfs(s, l, i) + dfs(s, i+1, r-1));
            }
        }
        return dp[l][r];
    }
};












class Solution {
public:
    int strangePrinter(string t) {
        if (t.empty()) return 0;
        string s;
        for (auto c : t) {
            if (s.empty() || c != s.back()) s += c;
        } 
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int len = 0; len < n; ++len) {
            for (int i = 0; i < n - len; ++i) {
                int j = i + len;
                dp[i][j] = len + 1;
                for (int k = i; k < j; ++k) {
                    if (s[k] == s[j]) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] - 1);
                    else dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};