#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    using pii = pair<int, int>;
    static constexpr int dirs[5] = {-1,0,1,0,-1};
    
    struct Dwell {
        pii box, man;
        Dwell(int _bx, int _by, int _mx, int _my): box(_bx, _by), man(_mx, _my) {}
        Dwell(pii b, pii m) : box(b), man(m) {}
    };
public:
    static int minPushBox(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dist[n][m][n][m];
        memset(dist, -1, sizeof(dist));
        
        pii box, start, end;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '0') box = {i, j};
                else if (grid[i][j] == 'S') start = {i, j};
                else if (grid[i][j] == 'E') end = {i, j};      
            }
        }

        auto inside = [n, m](int x, int y) {
            return x >= 0 && x < n && y >= 0 && y < m;
        };
        auto getDist = [&dist](pii b, pii m) -> int& {
            return dist[b.first][b.second][m.first][m.second];
        };

        queue<Dwell> q;
        q.emplace(box, start);
        getDist(box, start) = 0;

        while (!q.empty()) {
            Dwell cur = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                pii man_next(cur.man.first + dirs[i], cur.man.second + dirs[i+1]);
                auto [m_nx, m_ny] = man_next;
                if (!inside(m_nx, m_ny)) continue;
                if (cur.box == man_next) {
                    pii box_next(cur.box.first + dirs[i], cur.box.second + dirs[i+1]);
                    auto [b_nx, b_ny] = box_next;
                    if (!inside(b_nx, b_ny)) continue;
                    if (grid[b_nx][b_ny] != '#' && getDist(box_next, man_next) == -1) {
                        q.emplace(box_next, man_next);
                        getDist(box_next, man_next) = getDist(cur.box, cur.man) + 1;
                        if (box_next == end) {
                            return getDist(box_next, man_next);
                        }
                    }
                }
                else if (grid[m_nx][m_ny] != '#' && getDist(cur.box, man_next) == -1) {
                    q.emplace(cur.box, man_next);
                    getDist(cur.box, man_next) = getDist(cur.box, cur.man) + 1;
                }
            }
        }
        return -1;
    }
};


int main() {
    int n, m;
    scanf("%d%d\n", &n, &m);
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%c", &grid[i][j]);
        }
        getchar();
    }
    cout << Solution::minPushBox(grid) << "\n";
}