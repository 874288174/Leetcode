class Solution {
public:
    int totalNQueens(int n) {
        this->col.resize(n, false);
        this->main_diag.resize(2*n-1, false);
        this->anti_diag.resize(2*n-1, false);
        return dfs(0, n);
    }
    
private:
    vector<bool> col;
    vector<bool> main_diag;
    vector<bool> anti_diag;
    
    int dfs(int x, int n) {
        if (x == n) return 1;
        int res = 0;
        for (int y = 0; y < n; y++) {
            if (!col[y] && !main_diag[x+y] && !anti_diag[x-y+n-1]){
                col[y] = main_diag[x+y] = anti_diag[x-y+n-1] = true;
                res += dfs(x+1, n);
                col[y] = main_diag[x+y] = anti_diag[x-y+n-1] = false;
            }
        }
        return res;
    }
};
