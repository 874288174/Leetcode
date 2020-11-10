class SnakeGame {
public:
    SnakeGame(int width, int height, vector<vector<int>> &food) {
        g.resize(n = height, vector<int> (m = width, -1));
        this->food = food;
    }
 
    int move(string direction) {
        g[x][y] = mp[direction];
        x += dir[mp[direction]].first, y += dir[mp[direction]].second;
        if (x < 0 || x >= n || y < 0 || y >= m) return -1;
        if (k < food.size() && x == food[k][0] && y == food[k][1]) {
            k++; 
            score++;
        } else{ 
            int new_xx = xx + dir[g[xx][yy]].first, new_yy = yy + dir[g[xx][yy]].second;
            g[xx][yy] = -1;
            xx = new_xx, yy = new_yy;
        }
        return g[x][y] == -1 ? score : -1;
    }
    
private:
    map<string, int> mp{{"U", 0}, {"D", 1}, {"L", 2}, {"R", 3}};
    vector<pair<int, int>> dir{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int n, m, score = 0, k = 0;
    int x = 0, y = 0, xx = 0, yy = 0;
    vector<vector<int>> food, g;
};
