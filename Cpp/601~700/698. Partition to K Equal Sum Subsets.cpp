class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
		int n = nums.size();
        vector<bool> dp(1<<n, false);
        vector<int> total(1<<n, 0);
		dp[0] = true;
		
		int S = accumulate(nums.begin(), nums.end(), 0);
        if (S % k != 0) return false;
        S /= k;
        sort(nums.begin(), nums.end());
		if (nums.back() > S) return false;
		for(int i = 0; i < (1<<n); i++) {
			if (!dp[i]) continue;
			for(int j = 0; j < n; j++) {
				int temp = i | (1 << j);
				if (temp != i) {
					if (nums[j] > (S- total[i] % S)) break;
					dp[temp] = true;
					total[temp] = nums[j] + total[i];
				}
			}
		}
		return dp[(1<<n) - 1];
    }
};