class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, res = 0;
        for (const auto &i : nums) {
            if (i)  res = max(res, ++cnt);
            else cnt = 0;
        }
        return res;
    }
};