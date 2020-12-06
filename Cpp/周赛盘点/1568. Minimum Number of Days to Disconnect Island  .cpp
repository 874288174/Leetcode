class Solution {
public:
    vector<int> dirs = {-1,0,1,0,-1};
    int n, m;
    vector<pair<int, int>> v;
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int t = 0, cnt;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ++t;
                    cnt = dfs(i, j, grid, -1);
                }
            }
        }
        if (t != 1) return 0;
        if (cnt == 1) return 1;
        
        int p = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] != 0) {
                    grid[i][j] = 0;
                    int pp = p == -1 ? 1 : -1;
                    int k = !!(pair<int, int>{i, j} == v[0]); 
                    int cnt0 = dfs(v[k].first, v[k].second, grid, pp);
                    if (cnt0 != cnt-1) return 1;
                    grid[i][j] = p = pp;
                }
            }
        }
        return 2;
    }
    
    bool inside(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int dfs(int i, int j, vector<vector<int>>& grid, int p) {
        grid[i][j] = p;
        if (v.size() < 2) v.emplace_back(i, j);
        int cnt = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dirs[k], y = j + dirs[k+1];
            if (!inside(x, y) || grid[x][y] != (p == 1 ? -1 : 1)) continue;
            cnt += dfs(x, y, grid, p);
        }
        return cnt;
    }
};