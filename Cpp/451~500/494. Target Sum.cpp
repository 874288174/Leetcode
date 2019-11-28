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
        return dfs(nums, 0, S);
    }
private:
    int dfs(vector<int>& nums, int cur, long S) {
        if (cur == nums.size()) return S == 0 ? 1 : 0; 
        return dfs(nums, cur+1, S+nums[cur])
               + dfs(nums, cur+1, S-nums[cur]);  
    }
};
*/