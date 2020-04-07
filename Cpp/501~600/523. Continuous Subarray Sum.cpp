class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size(), sum = 0;
        unordered_map<int, int> modk;
        modk[0] = -1;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
			// 特例 k == 0
            int mod = k == 0 ? sum : sum % k;
            if (modk.count(mod)) {
                if (modk[mod] != i-1) return true;
            }
            else modk[mod] = i;
        }
        return false;
    }
};