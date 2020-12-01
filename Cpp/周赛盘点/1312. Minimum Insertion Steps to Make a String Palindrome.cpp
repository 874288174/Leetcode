class Solution {
public:
    int minInsertions(string s) {
        dp.resize(s.length(), vector<int> (s.length(), -1));
        return dfs(0, s.length()-1, s);
    }

private:
    vector<vector<int>> dp;
    
    int dfs(int i, int j, string &s) {
        if (i >= j) return 0;
        else if (dp[i][j] != -1) return dp[i][j];
        int ret;
        if (s[i] == s[j]) ret = dfs(i+1, j-1, s);
        else ret = 1 + min(dfs(i+1, j, s), dfs(i, j-1, s));
        return dp[i][j] = ret;
    }
};




class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                dp[i + 1][j + 1] = s[i] == s[n - 1 - j] ? dp[i][j] + 1 : max(dp[i][j + 1], dp[i + 1][j]);
        return n - dp[n][n];
    }
};