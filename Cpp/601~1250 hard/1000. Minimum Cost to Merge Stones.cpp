class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        int n = stones.size();
        if ((n - 1) % (K - 1)) return -1;
        vector<int> preS{0};        
        partial_sum(stones.begin(), stones.end(), back_inserter(preS));

        vector<vector<int> > dp(n, vector<int>(n));
        for (int len = K; len <= n; ++len) {
            for (int i = 0, j = len-1; j < n; ++i, ++j) {
                dp[i][j] = INT_MAX;
                for (int mid = i; mid < j; mid += K - 1)
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                if ((j - i) % (K - 1) == 0)
                    dp[i][j] += preS[j + 1] - preS[i];
            }
        }
        return dp[0][n - 1];
    }
};