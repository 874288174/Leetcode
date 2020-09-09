class Solution {
public:
    vector<vector<int>> dirs {{1, 0}, {0, 1}, {1, 1}};
    vector<int> pathsWithMaxScore(vector<string>& board) {
        auto sz = board.size();
        vector<vector<int>> score(sz + 1, vector<int>(sz + 1)), paths(sz + 1, vector<int>(sz + 1));
        board[0][0] = board[sz - 1][sz - 1] = '0';
        paths[0][0] = 1;
        for (int i = 1; i <= sz; ++i) {
            for (int j = 1; j <= sz; ++j) {
                if (board[i - 1][j - 1] == 'X') 
                    continue;
                for (auto d : dirs) {
                    auto i1 = i - d[0], j1 = j - d[1];
                    auto val = score[i1][j1] + (board[i - 1][j - 1] - '0');
                    if (score[i][j] <= val && paths[i1][j1] > 0) {
                        paths[i][j] = ((score[i][j] == val ? paths[i][j] : 0) + paths[i1][j1]) % 1000000007; 
                        score[i][j] = val;
                    }
                }
            }
        }
        return {paths[sz][sz] ? score[sz][sz] : 0, paths[sz][sz]};
    } 
};



class Solution {
public:
    long MOD;
    pair<int, long> dp[101][101];
    pair<int, long> f(vector<string>& A, int i, int j) {
        int n = A.size(), m = A[0].size();
        if(i >= n || j >= m || A[i][j] == 'X')
            return { -1e5, 0 };
        int val = A[i][j] - '0';
        if(A[i][j] == 'E')
            val = 0;
        if(i == n - 1 && j == m - 1)
            return { 0, 1 };
        pair<int, long> p1 = { -1, -1ll };
        if(dp[i][j] != p1)
            return dp[i][j];
        auto op1 = f(A, i + 1, j);
        auto op2 = f(A, i, j + 1);
        auto op3 = f(A, i + 1, j + 1);
        int cnt = 0;
        int ans = val + max(op1.first, max(op2.first, op3.first));
        if(val + op1.first == ans) cnt += op1.second; cnt %= MOD;
        if(val + op2.first == ans) cnt += op2.second; cnt %= MOD;
        if(val + op3.first == ans) cnt += op3.second; cnt %= MOD;
        return dp[i][j] = { ans, cnt % MOD };
    }
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        MOD = 1e9 + 7;
        pair<int, int> p1 = { -1, -1ll };
        for(int i = 0; i <= 100; i++)
            for(int j = 0; j <= 100; j++)
                dp[i][j] = p1;
        auto p = f(board, 0, 0);
        if(p.first <= 0)
            p.first = 0;
        return { p.first, (int)p.second };
    }
};