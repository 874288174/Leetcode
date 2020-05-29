class Solution {
public:  
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int res = 0, n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != '0') {
                    dfs(i, j, n, m, grid);
                    res++;
                }
            }
        }
        return res;
    }

private:
    const int dx[4] = {1, -1, 0, 0};
    const int dy[4] = {0, 0, 1, -1};
    
    void dfs(int x, int y, int n, int m, vector<vector<char>>& grid) {
        grid[x][y] = '0';
        for (int k = 0; k < 4; k++) {
            int xx = x+dx[k], yy = y+dy[k];
            if (xx >= n || yy >= m || xx < 0 || yy < 0) continue;
            if (grid[xx][yy] != '0') dfs(xx, yy, n, m, grid);
        }
    }
};