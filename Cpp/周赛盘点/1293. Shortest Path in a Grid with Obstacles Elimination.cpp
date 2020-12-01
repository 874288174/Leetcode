class Solution {
public:
    const vector<vector<int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        if (max(0, n + m - 2) <= k-1) return max(0, n + m - 2);

        queue<tuple<int, int, int>> q; 
        q.emplace(0,0,k);
        vector<int> visited(n*m, -1);
        visited[0] = k;
        int steps = 0, res = n*m;
        while (!q.empty()) {
            steps++;
            int sz = q.size();
            while (sz--) {
                //int x = get<0>(q.front()), y = get<1>(q.front()), k = get<2>(q.front());
                auto [x, y, k] = q.front();
                q.pop();
                for (const auto& d : dirs) {
                    int xx = x + d[0], yy = y + d[1];
                    if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                    int kk = k - grid[xx][yy];
                    if (visited[xx*m+yy] >= kk) continue;
                    int stepsToTarget = n-1-xx+m-1-yy;
                    if (stepsToTarget-1 <= kk) 
                        res = min(res, steps+stepsToTarget);
                    if (stepsToTarget == 0) continue;
                    q.emplace(xx,yy,kk);
                    visited[xx*m+yy] = kk;
                }
            }
        }
        return res != n*m ? res : -1;
    }
};