// 2 live -> dead
// -1 dead-> live
// 1 live -> live
// 0 dead -> dead


class Solution {  
public:
    int n, m;
    const int dx[8] = {1,1,1,0,0,-1,-1,-1};
    const int dy[8] = {1,0,-1,1,-1,1,0,-1};
    bool inside(int x, int y){
        return (x >= 0 && x < n && y >= 0 && y < m);
    }

    void gameOfLife(vector<vector<int>>& board) {
        n = board.size(), m = board[0].size();
        for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
              int cnt = 0;
              for (int k = 0; k < 8; k++){
                  int x = i+dx[k], y = j+dy[k];
                  if(inside(x, y) && board[x][y] > 0) cnt++;
              }
               if (board[i][j] > 0)  board[i][j] = (cnt < 2 || cnt > 3) ? 2 : 1;
               else  board[i][j] = (cnt == 3) ? -1 : 0;
           } 
        }
       for (int i = 0; i < n; i++) {
          for (int j = 0; j < m; j++){ 
             board[i][j] = (board[i][j] == 2 || board[i][j] == 0) ? 0 : 1;
          }
       } 
    }  
};