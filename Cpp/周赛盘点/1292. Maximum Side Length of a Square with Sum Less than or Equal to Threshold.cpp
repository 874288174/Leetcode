class Solution {
    vector<vector<int>> preS;
        
    int squareSum(int x1, int y1, int x2, int y2) {
        return preS[x2][y2] - preS[x1][y2]
                - preS[x2][y1] + preS[x1][y1];
    }
public:
    int maxSideLength(vector<vector<int>>& mat, int t) {
        int m = mat.size(), n = mat[0].size();
        preS.resize(m+1, vector<int>(n+1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                preS[i][j] = preS[i-1][j] + preS[i][j-1]
                            - preS[i-1][j-1] + mat[i-1][j-1];
            }
        }
        int res = 0;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                int len = res+1;
                while (i+len <= m && j+len <= n && squareSum(i, j, i+len, j+len) <= t) {
                    res = len++;
                }
            }
        }
        return res;
    }
};