class Solution {
private:
    using ll = long long;
public:
    int minSkips(vector<int>& dist, int speed, int hoursBefore) {
        int n = dist.size(), p = 0;
        vector<vector<ll>> f(2, vector<ll>(n + 1, LLONG_MAX / 2));
        f[0][0] = 0;
        
        for (int i = 1; i <= n; ++i) {
            auto &cur = f[p^1], &pre = f[p];
            for (auto &j : cur) j = LLONG_MAX / 2;

            for (int j = 0; j <= i; ++j) {
                if (j != i)
                    cur[j] = min(cur[j], ((pre[j] + dist[i - 1] - 1) / speed + 1) * speed);
                if (j != 0)
                    cur[j] = min(cur[j], pre[j - 1] + dist[i - 1]);
            }
            p ^= 1;
        }

        auto it = find_if(f[p].begin(), f[p].end(), [&](ll a) -> bool {return a <= 1ll * hoursBefore * speed;});
        if (it == f[p].end()) return -1;
        else return distance(f[p].begin(), it);
    }
};
