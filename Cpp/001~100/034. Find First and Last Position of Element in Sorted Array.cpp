class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        /*
        if (nums.empty()) return {-1, -1};
        auto p = equal_range(nums.begin(), nums.end(), target);
        if (p.first == nums.end() || *(p.first) != target) return {-1, -1};
        else return {p.first-nums.begin(), p.second-nums.begin()-1};
        */
        vector<int> res{-1, -1};
        if (nums.empty()) return res;
        int left = 0, right = nums.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) left = mid + 1;
            else right = mid;
        }
        if (left == nums.size() || nums[left] != target) return res;
        res[0] = left;
        right = nums.size();
        while (left < right) {
            int mid = left + (right-left) / 2;
            if (nums[mid] <= target) left = mid+1;
            else right = mid;
        }
        res[1] = left-1; //or right-1;
        return res;
    }
};
