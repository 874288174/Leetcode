class Solution {
public:
    int n;
    
    bool canRotate(vector<vector<int>>& g, int i, int j) {
        return i < n-1 && j < n-1
            && !g[i+1][j] && !g[i][j+1] && !g[i+1][j+1];
    }
    
    bool canGoDown(vector<vector<int>>& g, int i, int j, bool vertical) {
        if (vertical) 
            return i < n-2 && !g[i+2][j];
        else 
            return i < n-1 && !g[i+1][j] && !g[i+1][j+1];
    }
    
    bool canGoRight(vector<vector<int>>& g, int i, int j, bool vertical) {
        if (!vertical) 
            return j < n-2 && !g[i][j+2];
        else 
            return j < n-1 && !g[i][j+1] && !g[i+1][j+1];
    }
    
    int minimumMoves(vector<vector<int>>& grid, int steps = 0) {
        n = grid.size();
        queue<array<int, 3>> q;
        q.push({ 0, 0, false });
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto& a = q.front();
                if (a[0] == n-1 && a[1] == n-2) return steps;
                if ((grid[a[0]][a[1]] & (a[2] ? 2 : 4)) == 0) {
                    grid[a[0]][a[1]] = grid[a[0]][a[1]] | (a[2] ? 2 : 4);
                    if (canGoDown(grid, a[0], a[1], a[2])) q.push({ a[0] + 1, a[1], a[2] });
                    if (canGoRight(grid, a[0], a[1], a[2])) q.push({ a[0], a[1] + 1, a[2] });
                    if (canRotate(grid, a[0], a[1])) q.push({ a[0], a[1], a[2] ? false : true });
                }
                q.pop();
            }
            ++steps;
        }
        return -1;
    }
};