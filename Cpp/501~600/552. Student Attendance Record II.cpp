class Solution {
public:
    int checkRecord(int n) {
        if (n <= 0) return 0;
        vector<vector<long long>> v(2, vector<long long>(6, 0));
        const long long Mod = 1e9+7;
        v[0][0] = 1;
        int k = 0;
        while (n--) {
            auto &pre = v[k], &cur = v[k^1];
            cur[0] = (pre[0] + pre[1] + pre[2]) % Mod;
            cur[1] = pre[0];
            cur[2] = pre[1];
            cur[3] = (cur[0] + pre[3] + pre[4] + pre[5]) % Mod;
            cur[4] = pre[3];
            cur[5] = pre[4];
            k ^= 1;
        }
        return (accumulate(v[k].begin(), v[k].end(), (long long)0)) % Mod;
    }
};