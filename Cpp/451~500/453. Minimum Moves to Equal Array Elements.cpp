class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long Min = nums[0], sum = 0;
        for (const auto &i : nums) {
            if (i < Min) Min = i;
            sum += i;
        }
        return sum - Min*nums.size();
    }
};