class Solution {
public:
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,-1,1};
    int n, m;
    vector<pair<int, int>> v;
    
    int minDays(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();
        int t = 0, cnt, cnt0;
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
                    int pp = p == -1?1:-1;
                    if (i == v[0].first && j == v[0].second) 
                        cnt0 = dfs(v[1].first, v[1].second, grid, pp);
                    else cnt0 = dfs(v[0].first, v[0].second, grid, pp);
                    if (cnt0 != cnt-1) return 1;
                    grid[i][j] = pp;
                    p = pp;
                }
            }
        }
        return 2;
    }
    
    int dfs(int i, int j, vector<vector<int>>& grid, int p) {
        grid[i][j] = p;
        if (v.size() < 2) v.emplace_back(i, j);
        int res = 1;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || y < 0 || x >= n || y >= m || grid[x][y] != (p==1?-1:1)) continue;
            res += dfs(x, y, grid, p);
        }
        return res;
    }
};