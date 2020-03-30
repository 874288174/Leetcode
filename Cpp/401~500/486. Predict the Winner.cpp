class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size(), S = 0;
        if (n % 2 == 0) return true;
        dp.resize(n, vector<int>(n, 0));
        for (auto &i : nums) sum.push_back(S += i);
        return 2*f(0, n-1, nums) >= S;
    }
private:
    vector<vector<int>> dp;
    vector<int> sum;
    int get_sum(int i, int j) {
        return sum[j] - (i ? sum[i-1] : 0);
    }
    
    int f(int i, int j, vector<int> &nums) {
        if (i == j) return nums[i];
        if (dp[i][j]) return dp[i][j];
        return dp[i][j] = max(get_sum(i+1, j) - f(i+1, j, nums)+nums[i],
                              get_sum(i, j-1) - f(i, j-1, nums)+nums[j]);
    }
};