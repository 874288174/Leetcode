class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> res;
        if (nums.empty()) return res;
        int n = nums.size(), p = 0;
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = {1, -1};
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j].first+1 > dp[i].first) {
                        dp[i] = {dp[j].first+1, j};
                    }
                }
            }
            if (dp[i].first > dp[p].first) p = i; 
        }
        while (p != -1) {
            res.push_back(nums[p]);
            p = dp[p].second;
        }
        return res;
    }
};