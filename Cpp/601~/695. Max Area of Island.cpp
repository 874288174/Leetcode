class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) { 
        n = grid.size(), m = grid[0].size();      
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]) {
                    res = max(res, dfs(i ,j, grid));
                }
            }
        }
        return res;
    }

private:
    int n, m;
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,-1,1};
    
    bool inside(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    int dfs(int x, int y, vector<vector<int>>& grid) {
        grid[x][y] = 0;
        int sum = 1;
        for (int k = 0; k < 4; k++) {
            int xx = dx[k] + x, yy = dy[k] + y;
            if (inside(xx, yy) && grid[xx][yy]) {
                sum += dfs(xx, yy, grid);
            }
        }
        return sum;
    }
};