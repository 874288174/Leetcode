class Solution {
public:
    using tuple3i = tuple<int, int, int>;
    const vector<int> dirs{0,1,0,-1,0};
    bool vis[31][31][64];
    
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size(), cnt = 0, keys = 0;
        tuple3i start;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@') {
                    vis[i][j][0] = true;
                    start = {i, j, 0};
                }
                else if (islower(grid[i][j])) {
                    keys |= 1 << (grid[i][j] - 'a');
                }
            }
        }
        if (keys == 0) return 0;
        
        queue<tuple3i> q;
        q.push(start);
        while (!q.empty()) {
            int sz = q.size();
            ++cnt;
            while (sz--) {
                auto [x, y, k] = q.front();
                q.pop();
                for (int i = 0; i < 4; ++i) {
                    int xx = x + dirs[i], yy = y + dirs[i+1], kk = k;
                    if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                    if (grid[xx][yy] == '#') continue;
                    else if (islower(grid[xx][yy])) {
                        kk |= 1 << (grid[xx][yy] - 'a');
                        if (kk == keys) return cnt;
                    }
                    else if (isupper(grid[xx][yy])) {
                        if (!(kk & (1 << (grid[xx][yy] - 'A')))) continue;
                    }
                    if (vis[xx][yy][kk]) continue;
                    vis[xx][yy][kk] = true;
                    
                    q.emplace(xx, yy, kk);
                }
            }
        }
        return -1;
    }
};