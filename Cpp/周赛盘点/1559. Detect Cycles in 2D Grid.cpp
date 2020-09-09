class Solution {
public:
    vector<vector<int>> v;
    
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        v.resize(n, vector<int> (m, -1));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (v[i][j] != -1) continue;
                if (dfs(i, j, n, m, i*m + n, grid)) return true;
            }
        }
        return  false;
    }
    const vector<int> dx{-1,1,0,0};
    const vector<int> dy{0,0,-1,1};
    
    bool dfs(int i, int j, int n, int m, int cnt, vector<vector<char>>& grid) {
        v[i][j] = ++cnt;
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];// cout << x << " " << y << "\n";
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (grid[x][y] != grid[i][j]) continue;
            if (v[x][y] != -1) {
                if (cnt - v[x][y] >= 3) return true;
            }
            else {
                if (dfs(x, y, n, m, cnt, grid)) return true;
            }
            
        }
        return false;
    }
};





class Solution {
public:
    vector<int> d = {1, 0, -1, 0, 1};
    bool containsCycle(vector<vector<char>>& g) {
        for (int i = 0; i < g.size(); ++i)
            for (int j = 0; j < g[i].size(); ++j) {
                if (g[i][j] >= 'a') {
                    char val = g[i][j];
                    vector<pair<int, int>> q = {{i, j}};
                    while (!q.empty()) {
                        vector<pair<int, int>> q1;
                        for (auto [x, y] : q) {
                            if (g[x][y] < 'a')
                                return true;
                            g[x][y] -= 26;
                            for (auto k = 0; k < 4; ++k) {
                                int dx = x + d[k], dy = y + d[k + 1];
                                if (dx >= 0 && dy >= 0 && dx < g.size() && dy < g[dx].size() && g[dx][dy] == val)
                                    q1.push_back({dx, dy});
                            }
                        }
                        swap(q, q1);
                    }
                }
            }
        return false;
    }
};