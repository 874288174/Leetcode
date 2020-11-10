class Solution {
public:
    struct node {
        int x, y, cnt;
        string s;
        node(int a, int b, int c, string d) : x(a), y(b), cnt(c), s(d) {}
    };

    using pis = pair<int, string>;
    
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int n = maze.size(), m = maze[0].size();
        vector<vector<pis>> visit(n, vector<pis>(m, {INT_MAX, "z"}));
        
        auto &res = visit[destination[0]][destination[1]];
        queue<node> pq;
        pq.emplace(start[0], start[1], 0, "");
        visit[start[0]][start[1]] = {0, ""};
        while (!pq.empty()) {
            auto u = pq.front();
            pq.pop();
            for (int k = 0; k < 4; ++k) {
                int x = u.x, y = u.y, c = u.cnt;
                while (1) {
                    int xx = x + dx[k], yy = y + dy[k];
                    if (xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy]) break;
                    x = xx; y = yy; ++c;
                    if (vector<int> {x, y} == destination) {
                        res = min(res, {c, u.s + dirs[k]});
                        break;
                    }
                }
                if (visit[x][y] < pis{c, u.s + dirs[k]}) continue;

                visit[x][y] = {c, u.s + dirs[k]};
                if (visit[x][y].first < res.first) {
                    pq.emplace(x, y, c, u.s + dirs[k]);
                }
            }
        }
        return res.first == INT_MAX ? "impossible" : res.second;
    }

private:
    const vector<int> dx{0, 0, 1, -1};
    const vector<int> dy{1, -1, 0, 0};
    string dirs = "rldu";
};