/*class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        int V = sum/2, n = nums.size();
        vector<bool> dp(V+1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = V; j >= 0; j--) {
                if (j < nums[i]) break;
                dp[j] = dp[j] || dp[j-nums[i]];
            }
            if (dp[V]) return true;
        }
        return false;
    }
};
*/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        bitset<100*200/2+1> bits(1);
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 2 != 0) return false;
        for (auto n : nums) bits |= bits << n;
        return bits[sum >> 1];
    }
};