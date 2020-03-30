class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true; 
        int S = accumulate(nums.begin(), nums.end(), 0);
        if (S % k != 0) return false;
        S /= k;
        sort(nums.begin(), nums.end(), greater<int> ());
        if (nums[0] > S) return false;
        int n = nums.size();
        vector<bool> visited(n, false);
        return dfs(0, -1, S, k, n, visited, nums);
    }
private:
    bool dfs(int cur, int preIndex, int S, int k, int n, vector<bool> &visited, vector<int>& nums) {
        if (k == 0) return true;
        if (cur > S) return false;
        else if (cur == S) return dfs(0, -1, S, k-1, n, visited, nums);
        for (int i = preIndex+1; i < n; ++i) {
            if (!visited[i]) {
               visited[i] = true;
               if (dfs(cur+nums[i], i, S, k, n, visited, nums)) return true;
               visited[i] = false;
            }
        }
        return false;
    }
};