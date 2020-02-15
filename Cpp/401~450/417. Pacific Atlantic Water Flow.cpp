class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        n = matrix.size(), m = matrix[0].size();
        buffer.resize(n, vector<int> (m, 0));
        visit.resize(n, vector<bool> (m, false));
        for (int j = 0; j < m; ++j) dfs(0, j, matrix);
        for (int i = 1; i < n; ++i) dfs(i, 0, matrix);
        visit = vector<vector<bool>>(n, vector<bool> (m, false));
        for (int j = 0; j < m; ++j) dfs(n-1, j, matrix);
        for (int i = 0; i < n-1; ++i) dfs(i, m-1, matrix);
        return res;
    }
private:
    int n, m;
    vector<vector<int>> res, buffer;
    vector<vector<bool>> visit;
    const vector<int> dx{0,0,1,-1};
    const vector<int> dy{-1,1,0,0};
    
    void dfs(int i, int j, vector<vector<int>>& matrix) {
        if (visit[i][j]) return;
        visit[i][j] = true;
        if (++buffer[i][j] == 2){
            res.push_back({i, j});
        }
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k], y = j + dy[k];
            if (x < 0 || y < 0 || x >= n || y >= m) continue;
            if (!visit[x][y] && matrix[x][y] >= matrix[i][j]) {
                dfs(x, y, matrix);
            }
        }
    }
};