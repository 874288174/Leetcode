class Solution {
public:
/*
  1，定义如下：
    sums[i]代表以nums[i]结尾的前k个数的和
    dp[i][j]代表截止到nums[i]形成的第j个无重叠子数组的最大和
    path[i][j]代表截止到nums[i]形成的第j个无重叠子数组以哪个下标为结尾，用来回溯路径
  2，状态转移方程为
    dp[i][j] = max{dp[i - 1][j], sums[i] + dp[i - k][j - 1]};
    path[i][j] = path[i - 1][j]或i
*/
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        return maxSumOfNSubarrays(nums, k, 3);
    }
private:
    vector<int> maxSumOfNSubarrays(vector<int>& nums, int k, int m) {
        vector<int> res;
        if (k < 1 || m * k > nums.size()) return res;
        int n = nums.size(), s = accumulate(nums.begin(), nums.begin() + k, 0);
        // 计算每个数的前缀和
        vector<int> preSum;
        partial_sum(nums.begin(), nums.end(), back_inserter(preSum));
        // 动态规划
        vector<vector<int>> dp(n, vector<int>(m + 1, 0));
        vector<vector<int>> path(n, vector<int>(m + 1, 0));
        dp[k-1][1] = preSum[k - 1];
        path[k-1][1] = k - 1;
        for (int i = k; i < n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                path[i][j] = path[i-1][j];
                if (dp[i][j] < preSum[i] - preSum[i-k] + dp[i-k][j-1]) {
                    dp[i][j] = preSum[i] - preSum[i-k] + dp[i-k][j-1];
                    path[i][j] = i;
                }
            }
        }
        // 路径回溯
        int pos = path[n-1][m];
        res.push_back(pos - k + 1);
        for (int i = m - 1; i > 0; --i) {
            pos = path[pos - k][i];
            res.push_back(pos - k + 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};