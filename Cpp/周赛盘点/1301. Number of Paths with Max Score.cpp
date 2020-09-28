class Solution {
public:
    vector<vector<int>> dirs {{1, 0}, {0, 1}, {1, 1}};
    vector<int> pathsWithMaxScore(vector<string>& board) {
        auto n = board.size();
        vector<vector<int>> score(n+1, vector<int>(n+1)), paths(n+1, vector<int>(n+1));
        board[0][0] = board[n-1][n-1] = '0';
        paths[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (board[i-1][j-1] == 'X') continue;
                for (auto d : dirs) {
                    auto x = i - d[0], y = j - d[1];
                    auto val = score[x][y]+(board[i-1][j-1]-'0');
                    if (score[i][j] <= val && paths[x][y] > 0) {
                        paths[i][j] = ((score[i][j] == val ? paths[i][j] : 0) + paths[x][y]) % 1000000007; 
                        score[i][j] = val;
                    }
                }
            }
        }
        return {paths[n][n] ? score[n][n] : 0, paths[n][n]};
    } 
};






class Solution {
public:
    long MOD = 1e9 + 7;
    vector<vector<pair<int, long>>> dp;
    int n, m;
    const int dir[4]{1, 0, 1, 1};
    
    pair<int, long> f(vector<string>& A, int i, int j) {
        if (i >= n || j >= m || A[i][j] == 'X') return {-1, 0};
        if (i == n-1 && j == m-1) return {0, 1};
        if (dp[i][j].second != -1) return dp[i][j];
        
        int val = A[i][j] == 'E' ? 0 : (A[i][j] - '0');
        vector<pair<int, long>> v;
        int pnt = -1;
        long cnt = 0;
        for (int k = 1; k < 4; ++k) {
            auto t = f(A, i+dir[k-1], j+dir[k]);
            pnt = max(pnt, t.first);
            v.emplace_back(t);
        }
        if (pnt < 0) return dp[i][j] = {-1, 0};
            
        for (auto &i : v) {
            if (pnt == i.first) {
                cnt += i.second;
            }
        }

        return dp[i][j] = {pnt+val, cnt % MOD};
    }
    
    vector<int> pathsWithMaxScore(vector<string>& A) {
        n = A.size(), m = A[0].size();
        dp.resize(n, vector<pair<int, long>> (m, {-1, -1ll}));
 
        auto p = f(A, 0, 0);
        if (p.first < 0) p.first = 0;
        return {p.first, static_cast<int>(p.second)};
    }
};