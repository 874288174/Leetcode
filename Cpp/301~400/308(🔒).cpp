// Binary Indexed Tree  现在不知道对不对
class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        mat.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        bit.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int diff = val - mat[row][col];
        mat[row][col] = val;
        for (int i = row + 1; i <= mat.size(); i += lowbit(i)) {
            for (int j = col + 1; j <= mat[i].size(); j += lowbit(j)) {
                bit[i][j] += diff;
            }
        }
    }

    int lowbit(int x) {
        return x & -x;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return getSum(row2 + 1, col2 + 1) - getSum(row1, col2 + 1) - getSum(row2 + 1, col1) + getSum(row1, col1);
    }
    
    int getSum(int row, int col) {
        int res = 0;
        for (int i = row; i > 0; i -= lowbit(i)) {
            for (int j = col; j > 0; j -= lowbit(j)) {
                res += bit[i][j];
            }
        }
        return res;
    } 
    
private:
    vector<vector<int>> mat;
    vector<vector<int>> bit;
};