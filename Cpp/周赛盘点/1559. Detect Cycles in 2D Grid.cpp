class Solution {
public:
    vector<vector<int>> v;
    int n, m;

    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        v.resize(n, vector<int> (m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] != -1) continue;
                if (dfs(i, j, i*m + n, grid)) return true;
            }
        }
        return  false;
    }
    const vector<int> dx{-1,1,0,0};
    const vector<int> dy{0,0,-1,1};
    
    bool dfs(int i, int j, int cnt, vector<vector<char>>& grid) {
        v[i][j] = ++cnt;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (grid[x][y] != grid[i][j]) continue;
            if (v[x][y] != -1) {
                if (cnt - v[x][y] >= 3) return true;
            }
            else {
                if (dfs(x, y, cnt, grid)) return true;
            }  
        }
        return false;
    }
};
