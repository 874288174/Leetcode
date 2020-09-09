class Solution {
public:
    int numOfWays(int n) {
        return (int)(6*(dp(0, n) + dp(1, n)) % MOD);
    }
    
    const long long MOD = 1e9 + 7;
    
    map<pair<int, int>, long long> mp;
    
    long long dp(int i, int j) {
        if (j == 1) return 1;
        if (mp.count({i, j})) return mp[{i, j}];
        long long res;
        if (i == 0) res = 3*dp(0, j-1) +2*dp(1, j-1);
        else res = 2*dp(0, j-1) +2*dp(1, j-1);
        return mp[{i, j}] = res % MOD;
    }
};





class Solution {
public:
    int numOfWays(int n) {
        long a121 = 6, a123 = 6, b121, b123, mod = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            b121 = a121 * 3 + a123 * 2;
            b123 = a121 * 2 + a123 * 2;
            a121 = b121 % mod;
            a123 = b123 % mod;
        }
        return (a121 + a123) % mod;
    }
};