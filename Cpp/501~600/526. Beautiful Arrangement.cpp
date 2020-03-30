class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums;
        for(int i = 0; i < N; i++) nums.push_back(i+1);
        return dfs(0, N, nums);
    }

private:
    int dfs(int i, int n, vector<int> &nums) {
        if (i == n) return 1;
        int res = 0;
        for (int j = i; j < n; ++j) {
            if (nums[j] % (i+1) == 0 || (i+1) % nums[j] == 0) {
                swap(nums[i],nums[j]);
                res += dfs(i+1, n, nums);
                swap(nums[i],nums[j]);
            }
        }
        return res;
    }
};