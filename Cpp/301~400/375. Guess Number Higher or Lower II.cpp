//存在O(n^2) algorithm， 待补充 

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