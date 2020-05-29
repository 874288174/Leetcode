class Solution {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        this->col.resize(n, false);
        this->main_diag.resize(2*n-1, false);
        this->anti_diag.resize(2*n-1, false);
        vector<string> v;
        dfs(0, n, v);
        return res;
    }
    
private:
    vector<bool> col;
    vector<bool> main_diag;
    vector<bool> anti_diag;
    void dfs(int x, int n, vector<string> &v) {
        if (x == n) {
           res.push_back(v);
           return;
        }
        for (int y = 0; y < n; y++) {
            if (!col[y] && !main_diag[x+y] && !anti_diag[x-y+n-1]){
                col[y] = main_diag[x+y] = anti_diag[x-y+n-1] = true;
                v.push_back( string(y,'.') + 'Q' + string(n-y-1,'.') );
                dfs(x+1, n, v);
                v.pop_back();
                col[y] = main_diag[x+y] = anti_diag[x-y+n-1] = false;
            }
        }
    }
};