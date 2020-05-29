class Solution {
public:
    int knightDialer(int N) {
        map<int, vector<int>> mp{{0, {4, 6}}, {1, {6, 8}}, {2, {7, 9}}, {3, {4, 8}},
                                 {4, {0, 3, 9}}, {5, {}}, {6, {0, 1, 7}}, {7, {2, 6}},
                                 {8, {1, 3}}, {9, {2, 4}}};
        vector<vector<long long>> dp(2, vector<long long>(10, 1));
        const long long MOD = 1e9 + 7;
        int k = 0;
        while (--N) {
            vector<long long> &pre = dp[k], &cur = dp[k^1];
            for (auto &i : cur) i = 0;
            for (int i = 0; i < 10; ++i) {
               for (auto j : mp[i]) {
                   cur[j] += pre[i];
               }
            }
            for (auto &i : cur) i %= MOD;
            k ^= 1;
        }
        return accumulate(dp[k].begin(), dp[k].end(), long(0)) % MOD;
    }
};