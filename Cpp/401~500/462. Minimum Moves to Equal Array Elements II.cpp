class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        long long med = nums[nums.size()/2], res = 0;
        for (const auto &i : nums) res += abs(i-med);
        return res;
    }
};