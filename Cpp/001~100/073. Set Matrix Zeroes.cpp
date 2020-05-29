class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if( matrix.empty() ) return;
        bool Row_Zero = false, Col_Zero = false;
        int N = matrix.size(), M = matrix[0].size();
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (!i && !matrix[i][j]) Row_Zero = true;
                if (!j && !matrix[i][j]) Col_Zero = true;
                if (!matrix[i][j])  matrix[i][0] = matrix[0][j]  = 0;
            }
        }
        
        for (int i = 1; i < N; i++) if( !matrix[i][0]){
            for(int j = 1; j < M; j++)   
               matrix[i][j] = 0;
        }
        
        
        for (int j = 1; j < M; j++) if( !matrix[0][j]){
            for(int i = 1; i < N; i++)   
               matrix[i][j] = 0;
        }
        
        if (Row_Zero){
           for (int j = 0; j < M; j++) matrix[0][j] = 0;
        }
        
        if (Col_Zero){
           for (int i = 0; i < N; i++) matrix[i][0] = 0;
        }
        return;
        
    }
};