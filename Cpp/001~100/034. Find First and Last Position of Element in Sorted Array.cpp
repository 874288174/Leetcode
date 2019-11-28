class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res{-1, -1};
        if(nums.empty()) return res;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (nums[right] != target) return res;
        res[0] = left;
        right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left+1) / 2;
            if (nums[mid] <= target) left = mid;
            else right= mid-1;
        }
        res[1] = right;
        return res;
    }
};