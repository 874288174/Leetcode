class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = 0, n = nums.size();
        for (auto &i : nums) sum += i;
        if ((sum-S) % 2 != 0 || S > sum) return 0;
        int newS = (sum + S) / 2;
        vector<int> dp(newS + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = newS; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }
        return dp[newS];
    }
};




/*
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size(), k = 1;
        vector<unordered_map<int, int>> dp(2);
        dp[0][0] = 1;
        for (int i = 0; i < n; ++i) {
            auto &cur = dp[k], &pre = dp[k^1];
            cur.clear();
            for (const auto &[j, t] : pre) {
                cur[j+nums[i]] += t;
                cur[j-nums[i]] += t;
            }
            k ^= 1;
        }
        return dp[k^1][S];
    }
};

*/