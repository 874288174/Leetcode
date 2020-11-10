class Solution {
public:
    const int dx[5] = {0, 0, 0, 1, -1};
    const int dy[5] = {0, 1, -1, 0, 0};
    using pii = pair<int, int>;

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 0x3f3f3f3f));
        dist[0][0] = 0;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, 0);
        vector<vector<bool>> vis(n, vector<bool>(m));
        while (!pq.empty()) {
            auto [cnt, pos] = pq.top();
            pq.pop();
            int y = pos % m, x = pos / m;
            if (vis[x][y]) continue;
            vis[x][y] = true;
            for (int k = 1; k <= 4; ++k) {
                int xx = x + dx[k], yy = y + dy[k];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                int nd = cnt + (grid[x][y] == k ? 0 : 1);
                if (nd >= dist[xx][yy]) continue;
                dist[xx][yy] = nd;
                pq.emplace(dist[xx][yy], xx * m + yy);
            }
        }
        return dist[n - 1][m - 1];
    }
};





class Solution {
public:
    const int dx[5] = {0, 0, 0, 1, -1};
    const int dy[5] = {0, 1, -1, 0, 0};
    using pii = pair<int, int>;

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        deque<pii> pq;
        pq.emplace_back(0, 0);
        vector<vector<bool>> vis(n, vector<bool>(m));
        while (!pq.empty()) {
            auto [cnt, pos] = pq.front();
            pq.pop_front();
            int x = pos / m, y = pos % m;
            if (vis[x][y]) continue;
            vis[x][y] = true;
            if (x == n - 1 && y == m - 1)
                return cnt;
            for (int k = 1; k <= 4; ++k) {
                int xx = x + dx[k], yy = y + dy[k];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (grid[x][y] == k) 
                    pq.emplace_front(cnt, xx * m + yy);
                else
                    pq.emplace_back(cnt + 1, xx * m + yy);
            }
        }
        return 0;
    }
};