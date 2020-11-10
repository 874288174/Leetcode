class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        return dfs(maze, maze.size(), maze[0].size(), start, destination);
    }
private:
    set<vector<int>> visited;
    const vector<int> dx{0, 0, 1, -1};
    const vector<int> dy{1, -1, 0, 0};

    bool dfs(vector<vector<int>>& maze, int n, int m, vector<int> start, vector<int>& destination) {
        if (start == destination) return true;
        visited.insert(start);
        for (int k = 0; k < 4; ++k) {
            int x = start[0], y = start[1];
            while (1) {
                int xx = x + dx[k], yy = y + dy[k];
                if (xx < 0 || yy < 0 || xx >= n || yy >= m || maze[xx][yy]) break;
                x = xx; y = yy;
            }
            if (visited.count({x, y})) continue;
            if (dfs(maze, n, m, {x, y}, destination)) return true;
        }
        return false;
    }
};