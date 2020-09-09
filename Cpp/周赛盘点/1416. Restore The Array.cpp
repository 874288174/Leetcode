class Solution {
public:
    int dp[100001] = {};
    int dfs(string &s, int i, int k) {
        if (i == s.size())
            return 1;
        if (s[i] == '0')
            return 0;
        if (!dp[i]) {
            for (long sz = 1, num = 0; i + sz <= s.size(); ++sz) {
                num = num * 10 + s[i + sz - 1] - '0';
                if (num > k)
                    break;
                dp[i] = (dp[i] + dfs(s, i + sz, k)) % 1000000007;
            }
        }
        return dp[i];
    }
    int numberOfArrays(string s, int k) {
        return dfs(s, 0, k);
    }
};





class Solution {
public:
    int numberOfArrays(string s, int k) {
        vector<int> dp(s.size() + 1);
        dp[s.size()] = 1; 
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0')
                continue;
            for (long sz = 1, n = 0; i + sz <= s.size(); ++sz) {
                n = n * 10 + s[i + sz - 1] - '0';
                if (n > k)
                    break;
                dp[i] = (dp[i] + dp[i + sz]) % 1000000007;
            }
        }
        return dp[0];
    }
};