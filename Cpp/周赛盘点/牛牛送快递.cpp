class Solution {
public:
    using ll = long long;
    using pdi = pair<double, int>;
    const ll MOD = 1e9+7;
    pdi myAdd(const pdi &a, const pdi &b) {
        return pdi(a.first+b.first, a.second*(ll)b.second % MOD);
    }
    
    pdi g[505][505];
    int C[1005][1005];
    double preLogSum[1005] = {0};
    
    int minDist(int n, int m, int s, int t, vector<vector<int> >& edge) {
        for (int i = 1; i <= 1000; ++i)
            preLogSum[i] = preLogSum[i-1] + log(i);
        for (int i = 0; i <= 1000; ++i) {
            C[i][0]=1;
            for (int j = 1;j <= i; ++j) {
                C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (i != j) g[i][j] = pdi(2e18,0);
                else g[i][j] = pdi(0, 1);
            }
        }
        for (auto e : edge) {
            int u = e[0], v = e[1];
            int a = e[2], b = e[3];
            pdi dis(preLogSum[a] - preLogSum[b] - preLogSum[a-b], C[a][b]);
            g[v][u] = g[u][v] = min(g[u][v], dis);
        }
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    g[i][j] = min(g[i][j], myAdd(g[i][k], g[k][j]));
        }
        return (g[s][t].second%MOD + MOD) % MOD;
    }
};