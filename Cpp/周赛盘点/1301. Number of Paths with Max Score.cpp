class Solution {
public:
  vector<vector<int>> dirs{{1, 0}, {0, 1}, {1, 1}};
  vector<int> pathsWithMaxScore(vector<string> &board) {
    auto n = board.size();
    vector<vector<int>> score(n + 1, vector<int>(n + 1)),
        paths(n + 1, vector<int>(n + 1));
    board[0][0] = board[n - 1][n - 1] = '0';
    paths[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (board[i - 1][j - 1] == 'X')
          continue;
        for (auto d : dirs) {
          auto x = i - d[0], y = j - d[1];
          auto val = score[x][y] + (board[i - 1][j - 1] - '0');
          if (score[i][j] <= val && paths[x][y] > 0) {
            paths[i][j] =
                ((score[i][j] == val ? paths[i][j] : 0) + paths[x][y]) %
                1000000007;
            score[i][j] = val;
          }
        }
      }
    }
    return {paths[n][n] ? score[n][n] : 0, paths[n][n]};
  }
};
