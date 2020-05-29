class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long Min = *min_element(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), static_cast<long long> (0));
        return sum - Min*nums.size();
    }
};
