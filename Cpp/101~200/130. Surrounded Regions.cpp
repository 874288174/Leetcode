class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        n = board.size(), m = board[0].size(); 
        for (int i = 0; i < n; i++) {
            dfs(i, 0, board);
            dfs(i, m-1, board);
        }
        
        for(int j = 1; j < m-1; j++) {
            dfs(0, j, board);
            dfs(n-1, j, board);
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] = board[i][j] == '+' ? 'O': 'X';
            }
        }
    }
    
private:
    int n, m;
    void dfs(int i, int j, vector<vector<char>>& board) {
        if (i < 0 || j < 0 || i >= n || j >= m) return;
        else if (board[i][j] != 'O') return;
        board[i][j] = '+';
        dfs(i+1, j, board);
        dfs(i-1, j, board);
        dfs(i, j+1, board); 
        dfs(i, j-1, board);
    }
};