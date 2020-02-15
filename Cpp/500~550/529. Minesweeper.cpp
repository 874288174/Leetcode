class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        n = board.size(), m = board[0].size();
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
        }
        else dfs(click[0], click[1], board);
        return board;
    }
private:
    int n, m;
    const vector<int> dx{0,0,-1,1,-1,1,-1,1};
    const vector<int> dy{-1,1,0,0,-1,1,1,-1};
    
    void dfs(int x, int y, vector<vector<char>>& board) {
        char cnt = '0';
        vector<pair<int, int>> book;
        for (int i = 0; i < 8; ++i) {
            int xx = x + dx[i], yy = y + dy[i];
            if (xx >= n || yy >= m || xx < 0 || yy < 0) continue;
            if (board[xx][yy] == 'M') ++cnt;
            if (board[xx][yy] == 'E')
                book.push_back({xx, yy});
        }
        board[x][y] = cnt == '0' ? 'B' : cnt;
        if (cnt == '0') {
            for (auto &pii : book) dfs(pii.first, pii.second, board); 
        }
    }
};
