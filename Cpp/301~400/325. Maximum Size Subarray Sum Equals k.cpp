class Solution {
public:
    int maxSubArrayLen(vector<int> &nums, int k) {
        int sum = 0, res = 0, n = nums.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum == k) res = i + 1;
            else if (m.count(sum - k)) res = max(res, i-m[sum-k]);
            if (!m.count(sum)) m[sum] = i;
        }
        return res;
    }
};