class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size(), i = k, j = k;
        int res = 0,  Min = nums[k];
        
        while (i >= 0 || j < n) {
            if (i < 0 || j < n && nums[i] <= nums[j]) {
                Min = min(Min, nums[j++]);
            }
            else if (j == n || i >= 0 && nums[i] >= nums[j]) {
                Min = min(Min, nums[i--]);
            }
            res = max(res, Min*(j-i-1));
        }
        return res;
    }
};