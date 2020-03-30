class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N, vector<vector<double>> (N, vector<double>(K, 0)));
        return dfs(r, c, 0, K, N, dp);
    }
private:
    const vector<int> dx{2, 1, -1, -2, -2, -1, 1, 2};
    const vector<int> dy{1, 2, 2, 1, -1, -2, -2, -1};


    double dfs(int r, int c, int k, int K, int N, vector<vector<vector<double>>> &dp) {
        if (r >= c) swap(r, c);        
        if (r < 0 || c >= N) return 0;
        if (k == K) return 1;
        if (dp[r][c][k] != 0) return dp[r][c][k];
        double res = 0.0;
        for (int t = 0; t < 8; ++t) {
            res += dfs(r + dx[t], c + dy[t], k+1, K, N, dp);
        }
        return dp[r][c][k] = 0.125*res;
    }
};