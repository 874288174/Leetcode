class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int N = nums.size();
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));
        for (int i = N; i >= 1; --i) {
            for (int j = i; j <= N; ++j) {
                int bestCoins = 0;
                for (int k = i; k <= j; ++k) {
                    int coins = dp[i][k-1] + dp[k+1][j]; 
                    coins += nums[i-1] * nums[k] * nums[j+1]; 
                    bestCoins = max(bestCoins, coins);
                }
                dp[i][j] = bestCoins;
            }
        }
        return dp[1][N];
    }
};
