class Solution {
public:
    int minimumIncompatibility(vector<int>& nums, int k) {
        int n = nums.size(), res = 0;
		if (k == nums.size()) return 0;
		if (n % k != 0) return -1;

		sort(nums.begin(), nums.end());
		int a = n / k, m = 1 << n;
        vector<int> dp(m, INT_MAX);
        map<int, int> mp;

        for (int i = 0; i < m; ++i) {
            if (__builtin_popcount(i) == a) {
                int big = INT_MIN, small = INT_MAX, pre = -1;
                bool ok = true;
                for (int j = 0; j < n; ++j) {
                    if ((1 << j) & i) {
                        if (pre == nums[j]) {ok = false; break;}
                        pre = nums[j];
                        if (small > nums[j]) small = nums[j];
                        if (big < nums[j]) big = nums[j];
                    }
                }
                if (!ok) continue;
                mp[i] = dp[i] = big - small;
            }
        }

        for (int i = 1; i < m; ++i) {
            int b = __builtin_popcount(i);
            if (b % a != 0 || dp[i] == INT_MAX) continue;
            for (auto &[j, cnt] : mp) {
                if ((i&j) == 0) {
                    dp[i|j] = min(dp[i|j], dp[i] + cnt);
                }
            }
        }

        return dp.back() == INT_MAX ? -1 : dp.back();
    }
};