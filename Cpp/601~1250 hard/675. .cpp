class Solution {
public:    
    const int dir[5] = {0, -1, 0, 1, 0};
    int n, m;
    
    int cutOffTree(vector<vector<int>>& v) {
        m = v.size(), n = v[0].size();
        vector<vector<int>> heights;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) if (v[i][j] > 1) {
            	heights.push_back({v[i][j], i, j});
            }
        }
        sort(heights.begin(), heights.end());
        int x = 0, y = 0, res = 0; 
        for (int i = 0; i < heights.size(); i++) {
            int cnt = BFS(v, x, y, heights[i][1], heights[i][2]); 
            if (cnt == -1) return -1;
            res += cnt;
            x = heights[i][1], y = heights[i][2];
        }
        return res;
    }
    
    int BFS(vector<vector<int>>& v, int x0, int y0, int x1, int y1){
        if (x0 == x1 && y0 == y1) return 0;
        int cnt = 0;
        queue<pair<int, int>> q;
        q.emplace(x0, y0);
        vector<vector<bool>> vis(m, vector<bool>(n));
        vis[x0][y0] = true;
        while(!q.empty()) {
            int sz = q.size();
            cnt++;
            while(sz--) {
                auto [cur_x, cur_y] = q.front();
                q.pop();
                for(int k = 0; k < 4; k++) {
                    int x = cur_x + dir[k], y = cur_y + dir[k+1];
                    if (x >= 0 && x < m && y >= 0 && y < n && v[x][y] && !vis[x][y]) {
                        if (x == x1 && y == y1) return cnt;
                        vis[x][y] = true;
                        q.emplace(x,y);
                    }
                }
            }
        }
        return -1;
    }
};
