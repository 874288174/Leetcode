class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        
        int m = matrix.size(), n = matrix[0].size(), flag = 0;
        for (int k = 0; k < m+n-1; k++) {
            int st = max(0, k+1-n), ed = min(m-1, k);
            if (flag) for (int i = st; i <= ed; i++) {
                res.push_back(matrix[i][k-i]);
            }
            else for (int i = ed; i >= st; i--) {
                res.push_back(matrix[i][k-i]);
            }
            flag ^= 1;
        }
        return res;
    }
};