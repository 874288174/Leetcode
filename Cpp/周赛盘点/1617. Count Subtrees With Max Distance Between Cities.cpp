class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dis(n, vector<int> (n, 1e9));
        vector<int> neig(n, 0), res(n-1, 0);
        vector<bool> vis(1<<n, false);
        for (auto &v : edges) {
            dis[v[0]-1][v[1]-1] = dis[v[1]-1][v[0]-1] = 1;
            neig[v[0]-1] |= 1 << (v[1]-1);
            neig[v[1]-1] |= 1 << (v[0]-1);
        }
        for (int i = 0; i < n; ++i) dis[i][i] = 0;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        for (int k = 1; k < (1 << n); ++k) {
            if (__builtin_popcount(k) == 1) vis[k] = true;
            if (!vis[k]) continue;
            int t = 0, d = 0;
            for (int i = 0; i < n; ++i) if (k & (1 << i)) t |= neig[i];  
            for (int i = 0; i < n; ++i) if (t & (1 << i)) vis[k | (1 << i)] = true;
      
            for (int i = 0; i < n; ++i) {
                if ((k & (1 << i))) {
                    for (int j = 0; j < n; ++j) {
                        if ((k & (1 << j))) {
                            d = max(d, dis[i][j]);
                        }
                    }
                }
            }
            if (d == 0) continue;
            ++res[d-1];
        }
        return res;
    }
};
