class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n =  matrix.size();
        int i = 0, j = n-1;
        while(i < j){
            for(int k = 0; k < n; k++)  swap(matrix[k][i], matrix[k][j]);
            i++; j--;
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j + i < n-1; j++)
                swap(matrix[i][j],matrix[n-1-j][n-1-i]);
    }
};