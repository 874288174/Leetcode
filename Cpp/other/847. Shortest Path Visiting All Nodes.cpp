class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        n = graph.size();
        dis.resize(n, vector<int> (n, inf));
        dp.resize(n, vector<int> (1<<(n+1), inf));
        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
            dp[i][1<<i] = 0;
            for (auto j : graph[i]) {
                dis[i][j] = dis[j][i] = 1;
            }
        }
        floyd(n);
        return DP();
    }
private:
    const int inf = 100; 
    int n;
    vector<vector<int>> dis;
    vector<vector<int>> dp;

    int DP() {
        for (int group = 1; group < (1<<n); group++) {
            for (int u = 0; u < n; u++) {
                for (int v = 0; v < n; v++) {
                    int src = 1 << u, dst = 1 << v;
                    if ((group & src) && !(group & dst))
                        dp[v][group|dst] = min(dp[u][group] + dis[u][v], dp[v][group|dst]);
                }
            }
        }
        int ret = inf;
        for (int i = 0; i < n; i++)
            ret = min(dp[i][(1<<n)-1], ret);
        return ret;
    }

    void floyd(int n) {
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
    }
};