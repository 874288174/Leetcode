class Solution {
public:
    struct node {
        int x, y, cnt;
        node(int a, int b, int c) : x(a), y(b), cnt(c) {}
    };

    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<int>> visit(n, vector<int>(m, INT_MAX));
        
        int &res = visit[destination[0]][destination[1]];
        queue<node> pq;
        pq.emplace(start[0], start[1], 0);
        visit[start[0]][start[1]] = 0;
        while (!pq.empty()) {
            auto u = pq.front();
            pq.pop();
            for (int k = 0; k < 4; ++k) {
                int x = u.x, y = u.y, c = u.cnt;
                while (1) {
                    int xx = x + dx[k], yy = y + dy[k];
                    if (xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy]) break;
                    x = xx; y = yy; ++c;
                }
                if (visit[x][y] <= c) continue;
                visit[x][y] = c;
                if (visit[x][y] < res) {
                    pq.emplace(x, y, c);
                }
            }
        }

        return res == INT_MAX ? -1 : res;
    }

private:
    const vector<int> dx{0, 0, 1, -1};
    const vector<int> dy{1, -1, 0, 0};
};