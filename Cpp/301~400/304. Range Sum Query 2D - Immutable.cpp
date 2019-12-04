class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix) {
        if (matrix.empty()) return;
        int n = matrix.size(), m = matrix[0].size();
        sum.resize(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            int rowSum = 0;
            for (int j = 0; j < m; j++) {
                rowSum += matrix[i][j];
                if (i == 0) sum[i][j] = rowSum;
                else sum[i][j] = sum[i-1][j]+rowSum; 
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (sum.empty()) return 0;
        return get_sum(row2, col2)+get_sum(row1-1, col1-1)
              -get_sum(row2, col1-1)-get_sum(row1-1, col2);
    }
private:
    vector<vector<int>> sum;
    int get_sum(int i, int j) {
        if (i < 0 || j < 0) return 0;
        else return sum[i][j];
    }
};
