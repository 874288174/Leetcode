class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for (auto &i : coins) {
            for (int s = 0; s <= amount; ++s) {
                dp[s] += dp[s-i];
            }
        }
        return dp[amount];
    }
};