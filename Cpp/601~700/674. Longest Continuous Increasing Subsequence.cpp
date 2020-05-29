class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int res = 1, left = 0, n = nums.size();
        for (int i = 1; i < n; i++) {
            if (nums[i] <= nums[i-1]) left = i;
            else res = max(res, i-left+1);
        }
        return res;
    }
};