class Solution {
public:
    struct node {
        node(int len, int x, int y, char c) : len(len), x(x), y(y), c(c) {}
        node() {}
        int len, x, y;
        char c;
        bool operator < (const node& rhs) const {
            return len < rhs.len;
        }
    };
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size(), m = b.size();
        vector<vector<node>> dp(n+1, vector<node> (m+1));

        for (int i = 1; i <= n; ++i) dp[i][0] = node(i, i-1, 0, a[i-1]);
        for (int j = 1; j <= m; ++j) dp[0][j] = node(j, 0, j-1, b[j-1]);
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (a[i-1] == b[j-1]) 
                    dp[i][j] = {dp[i-1][j-1].len + 1, i-1, j-1, a[i-1]};
                else if (dp[i][j-1] < dp[i-1][j]) 
                    dp[i][j] = {dp[i][j-1].len + 1, i, j-1, b[j-1]};
                else 
                    dp[i][j] = {dp[i-1][j].len + 1, i-1, j, a[i-1]};
            }
        }
        string res;
        int x = n, y = m;
        while (x || y) {
            res += dp[x][y].c;
            int xx = dp[x][y].x;
            y = dp[x][y].y;
            x = xx;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};