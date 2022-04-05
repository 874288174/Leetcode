
class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = 1 << 10;
        vector<unordered_map<int, int>> groups(k);
        vector<int> size(k);
        for (int i = 0; i < k; ++i) {
            for (int j = i; j < nums.size(); j += k) {
                groups[i][nums[j]]++;
                size[i]++;
            }
        }
        
        vector<int> dp(n, nums.size());
        dp[0] = 0;
        for (int i = 0; i < k; ++i) {
            int lo = *min_element(dp.begin(), dp.end());
            vector<int> ndp(n, lo + size[i]);
            for (int j = 0; j < n; ++j) {
                for (const auto &[p, freq] : groups[i]) {
                    int nxt = p ^ j;
                    ndp[nxt] = min(ndp[nxt], dp[j] + size[i] - freq);
                }
            }
            dp = move(ndp);
        }
        return dp[0];
    }
};
