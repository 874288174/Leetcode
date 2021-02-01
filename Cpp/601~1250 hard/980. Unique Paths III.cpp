class Solution {
public:
    const int dirs[5] = {1, 0, -1, 0, 1};
    int n, m;
    map<pair<int, int>, int> dp;
    
    bool inside(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    int dfs(vector<vector<int>>& g, int pos, int steps, int state) {
        int x = pos/m, y = pos%m, ret = 0;
        if (g[x][y] == 2) return 1 == steps;
        if (dp.count({pos, state})) return dp[{pos, state}];
        g[x][y] = -1;
        for (int k = 0; k < 4; ++k) {
            int xx = x + dirs[k], yy = y + dirs[k+1];
            if (!inside(xx, yy) || g[xx][yy] == -1) continue;
            int newPos = xx*m+yy;
            ret += dfs(g, newPos, steps-1, state|(1<<newPos));
        }
        g[x][y] = 0;
        return dp[{pos, state}] = ret;
    }
    int uniquePathsIII(vector<vector<int>>& g) {
        n = g.size(), m = g[0].size();
        int pos, steps = 0;
        for (auto i = 0; i < n; ++i) {
            for (auto j = 0; j < m; ++j) {
                if (g[i][j] == 1) pos = i*m + j;
                if (g[i][j] != -1) ++steps;
            }
        }
        return dfs(g, pos, steps, 0);
    }
};