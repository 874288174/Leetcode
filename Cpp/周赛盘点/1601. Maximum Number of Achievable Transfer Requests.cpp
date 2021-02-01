class Solution {
public:
    int maximumRequests(int N, vector<vector<int>>& a) {
        int n = a.size(), res = 0;
        for (int mask = 0; mask < 1<<n; ++mask) {
            if (__builtin_popcount(mask) <= res) continue;
            vector<int> ind(N, 0);
            for (int j = 0; j < n; ++j) {
                if (mask>>j & 1) {
                    ++ind[a[j][1]];
                    --ind[a[j][0]];
                }
            }
            bool ok = true;
            for (int x : ind) {
                if (x > 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) res = max(res, __builtin_popcount(mask));
        }
        return res;
    }
};