class Solution {
public:
    using pii = pair<int, int>;
    int maxValue(vector<vector<int>>& events, int k) {
        auto cmp = [](const auto &a, const auto &b) {
            return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];   
        };
        sort(events.begin(), events.end(), cmp);

        vector<vector<pii>> v(k+1, vector<pii> {1, pii {-1, 0}});
        int res = 0;
        for (const auto &ev : events) {
            int st = ev[0], ed = ev[1], val = ev[2];
            for (int i = k; i >= 1; --i) {
                auto it = prev(upper_bound(v[i-1].begin(), v[i-1].end(), pii{st-1, INT_MAX}));

                int tmp = it->second + val;
                if (tmp > v[i].back().second) {
                    v[i].emplace_back(ed, tmp);
                }
                res = max(tmp, res);
            }
        }
        return res;
    }
};