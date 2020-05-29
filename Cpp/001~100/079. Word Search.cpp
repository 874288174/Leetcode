class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        this->n = board.size();
        this->m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, word, board, visited))
                    return true;
            }
        }
        return false;
    }
    
    
private:
    int n, m;
    
    bool dfs(int i, int j, int cnt, string &s, 
             vector<vector<char>>& board, vector<vector<bool>> &visited) { 
        if(cnt == s.length()) return true;
        if (i < 0 || j < 0 || i >= n || j >= m) return false;
        else if (visited[i][j] || board[i][j] != s[cnt++]) return false;
        visited[i][j] = true;
        bool ret = dfs(i-1, j, cnt, s, board, visited) || 
                   dfs(i+1, j, cnt, s, board, visited) || 
                   dfs(i, j-1, cnt, s, board, visited) || 
                   dfs(i, j+1, cnt, s, board, visited);
        visited[i][j] = false;
        return ret;
    }
};