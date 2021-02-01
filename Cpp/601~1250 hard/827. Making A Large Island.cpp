class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int index = 2;
        
        unordered_map<int, int> mp;
        int res = 1;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    mp[index] = dfs(i, j, n, m, index, grid);
                    res = max(mp[index++], res);
                }
            }
        }

        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) if (!grid[i][j]) {
                set<int> st;
                for (auto [dx, dy] : dir) {
                    int x = i + dx, y = j + dy;
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    if (!grid[x][y]) continue;
                    st.insert(grid[x][y]);
                }
                int sum = 1;
                for (auto i : st) sum += mp[i];
                res = max(res, sum);
            }
        }
        return res;
    }
    
private:
    const vector<pair<int, int>> dir{{0, 1}, {1, 0}, {-1, 0}, {0, -1}};    
    
    int dfs(int i, int j, int n, int m, int index, vector<vector<int>>& grid) {
        int ret = 1;
        grid[i][j] = index;
        for (auto [dx, dy] : dir) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1) {
                ret += dfs(x, y, n, m, index, grid);
            }
        }
        return ret;
    }
};