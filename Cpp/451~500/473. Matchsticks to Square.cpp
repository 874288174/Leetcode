class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) return false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum % 4 != 0) return false;
        int n = nums.size(), all = (1 << n) - 1, target = sum / 4;
        vector<int> masks, validHalf(1 << n, false);
        for (int i = 0; i <= all; ++i) {
            int curSum = 0;
            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) curSum += nums[j];
            }
            if (curSum == target) {
                for (auto &mask : masks) {
                    if ((mask & i) != 0) continue;
                    int half = mask | i;
                    validHalf[half] = true;
                    if (validHalf[all ^ half]) return true;
                }
                masks.push_back(i);
            }
        }
        return false;
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
        return dfs(nums, nums.size()-1, vector<int> (4, sum/4));
    }
private:
    bool dfs(vector<int> &nums, int cur, vector<int> lens) {
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