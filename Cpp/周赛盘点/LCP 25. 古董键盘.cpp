class Solution {
public:
    const int mod = 1e9 + 7;

    int keyboard(int k, int n) {
    //26个字母可以看作26个组，每个组内有k次可 选择，而背包容量为n. 求装满容量n的背包，有多少种装的方法
    //dp[i][j]表示用了j个字母，构建序列长度为i的可能
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= 26; i++) {
            for(int j = n; j >= 0; j--) {
                long long t = 0;
                for(int x = min(j, k); x >= 0; --x) {
                    t += dp[j-x] * C(j, x);
                }
                dp[j] = t % mod;
            }
        }
        return static_cast<int> (dp[n]);
    }

    map<pair<int, int>, int> mp;

    int C(int m, int n) {
        if (m-n < n) return C(m, m-n);
        if (mp.count({m, n})) return mp[{m, n}];
        long long ans = 1, k = 1;
        while (k <= n) {
            ans = ((m-k+1)*ans) / k++;
        }
        return mp[{m, n}] = (int)(ans % mod);
    }
};



class Solution {
public:
    const int mod = 1e9 + 7;

    int keyboard(int k, int n) {
    //26个字母可以看作26个组，每个组内有k次可 选择，而背包容量为n. 求装满容量n的背包，有多少种装的方法
    //dp[i][j]表示用了j个字母，构建序列长度为i的可能
        vector<vector<long long>> dp(27, vector<long long>(n + 1, 0L));
        for(int i = 0; i <= 26; i++) dp[i][0] = 1;
        
        for(int i = 1; i <= 26; i++) {
            for(int j = 1; j <= n; j++) {
                for(int x = min(j, k); x >= 0; --x) {
                    dp[i][j] += dp[i-1][j-x] * C(j, x);
                }
                dp[i][j] %=  mod;
            }
        }
        return static_cast<int> (dp[26][n]);
    }

    map<pair<int, int>, int> mp;

    int C(int m, int n) {
        if (m-n < n) return C(m, m-n);
        if (mp.count({m, n})) return mp[{m, n}];
        long long ans = 1, k = 1;
        while (k <= n) {
            ans = ((m-k+1)*ans) / k++;
        }
        return mp[{m, n}] = (int)(ans % mod);
    }
};
