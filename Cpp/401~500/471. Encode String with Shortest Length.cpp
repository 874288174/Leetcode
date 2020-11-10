class Solution {
public:
    string encode(string s) {
        int n = s.size();
        vector<vector<string>> dp(n, vector<string>(n));
        for(int len=1; len <= n; ++len) {
            for(int i = 0, j = i+len-1; j < n; ++i, ++j){
                string& t = dp[i][j] = s.substr(i, len);
                if (len >= 5) {
                    //判断是不是可循环
                    int p = (t+t).find(t, 1);
                    if (p < t.size()){
                        t = to_string(t.size()/p) + "[" + dp[i][i+p-1] + "]";
                    }
                    for (int k = i; k < j; ++k) {
                        if (dp[i][k].size() + dp[k+1][j].size() < t.size()){
                            t =  dp[i][k] + dp[k+1][j];
                        }
                    }
                }
            }
        }
        return dp[0][n-1];
    }
};