class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x = 0, y = 0, z = 0, bit = 1;
        for (auto &i : nums) x ^= i;
        while ((bit & x) == 0) bit <<= 1;
        for (auto &i : nums) {
            if (bit & i) y ^= i;
            else z ^= i;
        }
        return {y, z};
    }
};