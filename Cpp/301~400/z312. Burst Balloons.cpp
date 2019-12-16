class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));
        for (int len = 1; len <= N; ++len) {
            for (int i = 1; i <= N - len + 1; ++i) {
                int k = i + len - 1;
                int bestCoins = 0;
                for (int j = i; j <= k; ++j) {
                    int coins = dp[i][j-1] + dp[j+1][k]; 
                    coins += nums[i-1] * nums[j] * nums[k+1]; 
                    bestCoins = max(bestCoins, coins);
                }
                dp[i][k] = bestCoins;
            }
        }
        return dp[1][N];
    }
};