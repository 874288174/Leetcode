class Solution {
public:
    const vector<int> dirs{0,1,0,-1,0};
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        vector<int> res(hits.size());

        for (int i = hits.size()-1; i >= 0; --i) {
            if (!grid[hits[i][0]][hits[i][1]]) hits[i][0] = -1;
            else grid[hits[i][0]][hits[i][1]] = 0;
        }
        
        int n = grid.size(), m = grid[0].size();
        
        vector<int> fa(n*m+1, -1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j]) {
                    if (i == 0) Union(i*m+j, n*m, fa);
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dirs[k], y = j + dirs[k+1];
                        if (x < 0 || y < 0 || x >= n || y >= m) continue;
                        if (!grid[x][y]) continue;
                        Union(i*m+j, x*m+y, fa);
                    }
                }
            }
        }
                
        for (int i = hits.size()-1; i >= 0; --i) {
            if (hits[i][0] == -1) continue;
            int cnt = 0, pos = hits[i][0]*m+hits[i][1];
            bool ok = false;
            
            grid[hits[i][0]][hits[i][1]] = 1;
            
            if (hits[i][0] == 0) {
                Union(pos, n*m, fa);
                ok = true;
            }
            set<int> st;
            for (int k = 0; k < 4; ++k) {
                int x = hits[i][0] + dirs[k];
                int y = hits[i][1] + dirs[k+1];
                if (x < 0 || y < 0 || x >= n || y >= m) continue;
                if (!grid[x][y]) continue;
                st.insert(find(x*m+y, fa));
            }
            for (auto id : st) {
                if (find(id, fa) != n*m) {
                    cnt -= fa[find(id, fa)];
                }
                else ok = true;
                Union(pos, id, fa);
            }
            if (ok) res[i] = cnt;
        }
        return res;
    }
    
    
    void Union(int x, int y, vector<int> &fa) {
        int fax = find(x, fa), fay = find(y, fa);
        if (fax != fay) {
            fa[max(fax, fay)] += fa[min(fax, fay)];
            fa[min(fax, fay)] = max(fax, fay);
        }
    }
    
    int find(int x, vector<int> &fa) {
        return fa[x] < 0 ? x : (fa[x] = find(fa[x], fa));
    }
};