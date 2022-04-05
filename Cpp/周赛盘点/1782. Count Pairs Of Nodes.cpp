class Solution {
public:
    using pii = pair<int, int>;

    vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> deg(n + 1, 0);
        int nEdges = edges.size();
        unordered_map<int, int> overlap;
        vector<pii> distinctEdges;
        
        auto encode = [n](int a, int b) -> int {return max(a, b) * (n + 1) + min(a, b);};
        for (const auto &e : edges) {
            int p = e[0], q = e[1];
            ++deg[p]; ++deg[q];
            int idx = encode(p, q);
            if (overlap[idx]++ == 0) {
                distinctEdges.emplace_back(p, q);
            }
        }

        vector<int> sortedDeg(deg.begin() + 1, deg.end());
        sort(sortedDeg.begin(), sortedDeg.end());
        
        vector<int> ret;
        for (auto i : queries) {
            int l = 0, r = n-1;
            int cnt = 0;
            while (l < n) {
                while (r > l && sortedDeg[l] + sortedDeg[r] > i) --r;
                cnt += (n - max(l, r) - 1);
                ++l;
            }

            for (const auto& [p, q] : distinctEdges) {
                int idx = encode(p, q), sum = deg[p] + deg[q];
                if (sum > i && sum - overlap[idx] <= i) --cnt;
            }
            ret.push_back(cnt);
        }
        return ret;
    }
};
