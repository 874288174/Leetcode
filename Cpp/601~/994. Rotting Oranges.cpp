class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int res = 0, cnt = 0, n = grid.size(), m = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) ++cnt;
                else if (grid[i][j] == 2) {
                    grid[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        
        const vector<int> dx{0, 0, -1, 1};
        const vector<int> dy{-1, 1, 0, 0};

        while (!q.empty() && cnt) {
            int sz = q.size();
            while (sz--) {
               auto u = q.front();
               q.pop();
               for (int k = 0; k < 4; ++k) {
                   int x = u.first + dx[k], y = u.second + dy[k];
                   if (x < 0 || y < 0 || x >= n || y >= m || !grid[x][y]) continue;
                   --cnt;
                   grid[x][y] = 0;
                   q.push({x, y});
               }
            }
            ++res;
        }
        return cnt == 0 ? res : -1;
    }
};