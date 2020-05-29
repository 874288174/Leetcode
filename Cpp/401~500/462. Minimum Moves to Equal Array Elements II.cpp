class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int half = nums.size()/2, res = 0;
        nth_element(nums.begin(), nums.begin() + half, nums.end());
        int med = nums[half];
        for (const auto &i : nums) res += abs(i-med);
        return res;
    }
};