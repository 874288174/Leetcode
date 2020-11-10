class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<int> col(n, 0), row(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'W') {
                    row[j] = col[i] = 0; 
                    continue;
                } 
                if (!col[i]) {
                    for (int jj = j; jj < m && grid[i][jj] != 'W'; jj++) {
                       if (grid[i][jj] == 'E') col[i]++;
                   }
                }
                if (!row[j]) {
                   for (int ii = i; ii < n && grid[ii][j] != 'W'; ii++) {
                       if (grid[ii][j] == 'E') row[j]++;
                   }   
                }
                if (grid[i][j] == '0') res = max(res, col[i]+row[j]);
            }
        }
        return res;
    }
};