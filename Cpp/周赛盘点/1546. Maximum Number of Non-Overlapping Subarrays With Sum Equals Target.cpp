class Solution {
public:
    unordered_map<int, int> mp{{0, 0}};

    int maxNonOverlapping(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++) {
            sum += nums[i-1];
            auto it = mp.find(sum - target);
            if (it == mp.end()) dp[i] = dp[i-1];
            else {
                dp[i] = max(dp[i-1], dp[it->second] + 1);
            }
            mp[sum] = i;
        }
        return dp.back();
    }
};



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
