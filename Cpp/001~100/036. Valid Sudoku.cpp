class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool used[9];
        for(int i = 0; i < 9; i++){
            fill(used, used+9, false);
            for(int j = 0; j < 9; j++)
                if(!check(board[i][j], used)) 
                    return false;
            fill(used, used+9, false);
            for(int j = 0; j < 9; j++)
                if(!check(board[j][i], used)) 
                    return false;
        }
        
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                fill(used, used+9, false);
                for(int a = 3*i; a < 3*i+3; a++)
                    for(int b = 3*j; b < 3*j+3; b++)
                         if(!check(board[a][b],used)) 
                             return false;
                }
        }
        return true;    
    }

    bool check(char a, bool used[]){
        if(a == '.') return true;
        if(used[a-'1']) return false;
        used[a-'1'] = true;
        return true;
    }
};