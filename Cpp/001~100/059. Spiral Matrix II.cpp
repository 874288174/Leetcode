class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x = 0, y = 0, cnt = 0;
        res[x][y] = ++cnt;
        while (cnt < n*n) {
            while (y+1 < n  && !res[x][y+1]) res[x][++y] = ++cnt;
            while (x+1 < n  && !res[x+1][y]) res[++x][y] = ++cnt;
            while (y-1 >= 0 && !res[x][y-1]) res[x][--y] = ++cnt;
            while (x-1 >= 0 && !res[x-1][y]) res[--x][y] = ++cnt;
        }
        return res;
    }
};