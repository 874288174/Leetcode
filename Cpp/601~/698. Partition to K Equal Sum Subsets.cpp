class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size(), all = 1 << n;
        if (n < k) return false;
        vector<int> dp(all, -1);
		dp[0] = 0;
		
		int S = accumulate(nums.begin(), nums.end(), 0); 
        if (S % k != 0) return false;
        S /= k;
        sort(nums.begin(), nums.end(), greater<int>());
		if (nums[0] > S) return false;
		for(int i = 0; i < all; i++) {
			if (dp[i] == -1) continue;
			for(int j = 0; j < n; j++) {
				int temp = i | (1 << j);
				if (temp != i) {
					if (nums[j] > S - dp[i]) break;
					dp[temp] = (nums[j] + dp[i]) % S;
				}
			}
		}
		return dp.back() != -1;
    }
};