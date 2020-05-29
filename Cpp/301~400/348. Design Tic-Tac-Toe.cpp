class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        this->n = n;
        R.resize(n, 0);
        C.resize(n, 0);
    }
    
    int move(int row, int col, int player) {
        int add = (player == 2) ? -1 : 1;
        if (judge(row, add, R) || judge(col, add, C)) return player;
        else if (row == col && judge_diag(0, add)) return player;
        else if (row + col == n-1 && judge_diag(1, add)) return player;
        else return 0;
    }
    
private:
    int n;
    vector<int> R, C, diag{0, 0};
    
    bool judge(int row, int add, vector<int> &R) {
        if (abs(R[row] += add) == n)  return true;    
        else return false;
    }
    
    bool judge_diag(int type, int add) {
        if (abs(diag[type] += add) == n) return true;   
        else return false;
    }
};

