class Solution {
public:
    // dp[left][k] means the minimal coding size for substring 
    // s[left:] and removing at most k chars
    int getLengthOfOptimalCompression(string s, int k) {
        memset(dp, -1, sizeof(dp));
        return dfs(s, 0, k);
    }
    
private:
    int dp[101][101];
    
    int dfs(string &s, int left, int K) {
        if (s.size() - left <= K) return 0;
        if (dp[left][K] >= 0) return dp[left][K];
        int k = K, cnt = 1;
        int res = k ? dfs(s, left + 1, k - 1) : 10000;
        for (int i = left + 1; i <= s.size(); ++i) {
            res = min(res, dfs(s, i, k) + 1 + xs(cnt));
            if (i == s.size()) break;
            if (s[i] == s[left]) ++cnt;
            else if (--k < 0) break;
        }
        return dp[left][K] = res;
    }
    
    int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
};






class Solution {
public:
    int xs(int x) { return x == 1 ? 0 : x < 10 ? 1 : x < 100 ? 2 : 3; }
    const int INF = 0x3f3f3f3f;

    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(k+2, INF));
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= k && j <= i; ++j) {
                if (j < k) dp[i][j+1] = min(dp[i][j+1], dp[i-1][j]);
                int cnt = 0, del = j;
                for (int m = i; m <= n; ++m){
                    s[m-1] == s[i-1] ? ++cnt : ++del;
                    if (del > k) break;
                    dp[m][del] = min(dp[m][del], xs(cnt) + 1 + dp[i-1][j]);
                }
            }
        }
        return dp[n][k];
    }
};