class Solution {
public:
    using pii = pair<int, int>;
    const vector<int> dirs{0, 1, 0, -1, 0};
    
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pii, vector<pii>, greater<>> pq;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                pq.emplace(grid[i][j], i*m+j);
            }
        }
        vector<int> fa(n*m, -1);
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int x = t.second / m, y = t.second % m;
            for (int i = 0; i < 4; ++i) {
                int xx = x + dirs[i], yy = y + dirs[i+1];
                if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
                
                if (grid[x][y] > grid[xx][yy]) {
                    Union(t.second, xx * m + yy, fa);
                    if (find(0, fa) == find(n*m-1, fa)) return t.first;
                }
            }
        }
        return -1;
    }
    
    void Union(int x, int y, vector<int> &fa) {
        int fax = find(x, fa);
        int fay = find(y, fa);
        if (fax != fay) {
            fa[fay] += fa[fax];
            fa[fax] = fay; 
        }
    }
    
    int find(int x, vector<int> &fa) {
        return fa[x] < 0 ? x : (fa[x] = find(fa[x], fa));
    }
};