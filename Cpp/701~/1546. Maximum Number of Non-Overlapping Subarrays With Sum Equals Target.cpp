class Solution {
public:
    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size(), res = 0;
        int pre = -1, sum = 0;
        unordered_map<int, int> mp{{0, -1}};
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (mp.count(sum - target)) {
                int p = mp[sum - target];
                if (p >= pre) {
                    ++res;
                    pre = i;
                }
            }
            mp[sum] = i;
        }
        return res;
    }
};
