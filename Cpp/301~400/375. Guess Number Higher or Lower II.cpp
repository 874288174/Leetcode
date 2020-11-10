class Solution {
public:
    int getMoneyAmount(int n) {
        dp.resize(n+1, vector<int>(n+1));
        return f(0, n);
    }
private:
    vector<vector<int>> dp;
    
    int f(int i, int j) {
        if (i >= j) return 0;
        else if (dp[i][j] > 0) return dp[i][j];
        else if (i == j) return dp[i][j] = i;
        dp[i][j] = INT_MAX;
        for (int k = i; k <= j; ++k) {
            dp[i][j] = min(dp[i][j], k + max(f(i, k-1), f(k+1, j)));
        }
        return dp[i][j];
    }
};









class Solution {
public:
    /*
        f(a, b) = min(k + max(f(a, k-1), f(k+1, b))), k = a...b
        先找交点k0
        f(a, k-1) + k单调递增， 取k = k0+1
        f(k+1, b) + k用deque维护， 取最小值
    */
    
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        for (int b = 2; b <= n; ++b) {
            int k0 = b - 1;
            deque<pair<int, int>> v;
            for (int a = b - 1; a > 0; --a) {
                while (dp[a][k0 - 1] > dp[k0 + 1][b]) --k0;
                while (!v.empty() && v.front().first > k0) v.pop_front();
                int vn = a + dp[a + 1][b];
                while (!v.empty() && vn < v.back().second) v.pop_back();
                v.emplace_back(a, vn);
                int u1 = dp[a][k0] + k0 + 1;
                int u2 = v.front().second;
                dp[a][b] = min(u1, u2);
            }
        }
        return dp[1][n];
    }
};