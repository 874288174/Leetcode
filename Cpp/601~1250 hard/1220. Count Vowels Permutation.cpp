class Solution {
public:
    int countVowelPermutation(int n) {
        long long cnt = 5, MOD = 1e9 + 7;
        vector<long long> pre(5, 1); //a, e, i, o, u
        while (--n) {
            vector<long long> cur(5, 0);
            cur[0] = (pre[1] + pre[2] + pre[4]) % MOD;
            cur[1] = (pre[0] + pre[2]) % MOD;
            cur[2] = (pre[1] + pre[3]) % MOD;
            cur[3] = (pre[2]) % MOD;
            cur[4] = (pre[2] + pre[3]) % MOD;
            cnt = 0;
            for (auto i : cur) cnt = (cnt + i) % MOD;
            pre = cur;
        }
        return cnt;
    }
};