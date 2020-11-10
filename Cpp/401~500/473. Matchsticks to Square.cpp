class Solution {
public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size(), all = 1 << n;
        if (n < 4) return false;
        vector<int> dp(all, -1);
		dp[0] = 0;
		
		int S = accumulate(nums.begin(), nums.end(), 0); 
        if (S % 4 != 0) return false;
        S /= 4;
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

/*
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        sort(nums.begin(), nums.end());
        vector<int> lens(4, sum/4);
        return dfs(nums, nums.size()-1, lens);
    }
private:
    bool dfs(vector<int> &nums, int cur, vector<int> &lens) {
        if (cur < 0) return true;
        for (int i = 0; i < 4; ++i) {
            if (lens[i] - nums[cur] >= 0) {
                lens[i] -= nums[cur];
                if (dfs(nums, cur-1, lens)) return true;
                lens[i] += nums[cur];
            }
        }
        return false;
    }
};
*/

