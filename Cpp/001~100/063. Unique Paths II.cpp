class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
        vector<long long> f(n, 0);
        f[n-1] = 1;
        for (int i = m-1; i >= 0; i--){
            for (int j = n-1; j >= 0; j--) {
                if (i == m-1 && j == n-1) continue;
                if (obstacleGrid[i][j]) f[j] = 0;
                else if (j != n-1) f[j] += f[j+1];  
            }
        }
        return f[0];
    }
};