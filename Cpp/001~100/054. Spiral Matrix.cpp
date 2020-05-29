class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty() || matrix[0].empty()) return res;
        int n = matrix.size(), m = matrix[0].size();
        int x = 0, y = 0, cnt = 0;
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, -1, 0, 1};
        int step[] = {n-1, m-1};
        while (1) {
            res.push_back(matrix[x][y]);
            if(y+1 == m) break;
            y++;
        }
        while (res.size() != n*m) {
            for (int k = 0; k < 4; k++) {
                for (int t = 0; t < step[k%2]; t++) {
                    x += dx[k], y += dy[k];
                    res.push_back(matrix[x][y]);
                    if(res.size() == n*m) return res;
                }
                step[k%2] -= 1;
            }
        }
        return res;
    }
};
