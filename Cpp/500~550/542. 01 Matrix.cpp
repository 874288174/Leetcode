class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        const int MAX = 10000+10;
        vector<vector<int>> res(n, vector<int>(m, MAX));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!matrix[i][j]) res[i][j] = 0;
                else {
                    int up = i ? res[i-1][j] : MAX;
                    int left = j ? res[i][j-1] : MAX;
                    res[i][j] = min(up, left)+1;
                }
            }
        }
        
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) if (matrix[i][j]) {    
                int down = i != n-1 ? res[i+1][j] : MAX;
                int right = j != m-1 ? res[i][j+1] : MAX;
                res[i][j] = min(res[i][j], min(down, right)+1);
            }
        }
        return res;
    }
};