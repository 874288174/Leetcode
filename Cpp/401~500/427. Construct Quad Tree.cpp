
class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return dfs(0, 0, n, n, grid);
    }
    
private:
    Node* dfs(int x1, int y1, int x2, int y2, vector<vector<int>>& grid) {
        int x_mid = x1 + (x2-x1)/2;
        int y_mid = y1 + (y2-y1)/2;
        int val = grid[x1][y1];
        for (int r = x1; r < x2; r++) {
            for (int c = y1; c < y2; c++) {
                if (grid[r][c] != val) {
                    return new Node(
                        true, false,
                        dfs(x1, y1, x_mid, y_mid, grid),
                        dfs(x1, y_mid, x_mid, y2, grid),
                        dfs(x_mid, y1, x2, y_mid, grid),
                        dfs(x_mid, y_mid, x2, y2, grid)
                    );
                }
            }
        }
        return new Node(val != 0, true, nullptr, nullptr, nullptr, nullptr);
    }
};
