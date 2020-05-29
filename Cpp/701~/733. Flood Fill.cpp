class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        n = image.size(), m = image[0].size();
        dfs(image, sr, sc, newColor, image[sr][sc]);
        return image;
    }

private:
    int n, m;
    vector<int> dx{-1,1,0,0};
    vector<int> dy{0,0,-1,1};
    
    bool inside(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }
    
    void dfs(vector<vector<int>>& image, int x, int y, int newColor, int oldColor) {
        image[x][y] = newColor;
        for (int k = 0; k < 4; k++) {
            int xx = dx[k] + x, yy = dy[k] + y;
            if (inside(xx, yy) && image[xx][yy] == oldColor) {
                dfs(image, xx, yy, newColor, oldColor);
            }
        }
    }
};