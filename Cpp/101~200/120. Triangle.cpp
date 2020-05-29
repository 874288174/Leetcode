class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> &f = triangle.back();
        for (int i = triangle.size()-2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                f[j] = min(f[j], f[j+1])+triangle[i][j];
            }
        }
        return f[0];
    }
};