class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0, right = nums.size();
        while (left +1 < right) {
            int mid = left + (right-left)/2;
            if (mid % 2) {
                if (nums[mid] != nums[mid-1]) right = mid;
                else left = mid + 1;
            }
            else {
                if (nums[mid] != nums[mid-1]) left = mid;
                else right = mid - 1;
            }
        }
        return nums[left];
    }
};