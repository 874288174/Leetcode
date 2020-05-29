class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        if (rooms.empty()) return;
        n = rooms.size(), m = rooms[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) dfs(i, j, 0, rooms);
            }
        }
    }

private:
    int n, m;
    vector<int> dx{0,0,-1,1};
    vector<int> dy{-1,1,0,0};
    
    void dfs(int x, int y, int cnt, vector<vector<int>> &rooms) {
        for (int k = 0; k < 4; k++) {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx >= 0 && yy >= 0 && xx < n && yy < m && rooms[xx][yy] > 0) {
                if (rooms[xx][yy] > cnt+1) {
                    dfs(xx, yy, rooms[xx][yy] = cnt+1, rooms);
                }
            }
        }
    }
};