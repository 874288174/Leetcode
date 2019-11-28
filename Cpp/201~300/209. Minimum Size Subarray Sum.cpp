class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        int left = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            while (sum >= s) {
                ans = min(ans, i + 1 - left);
                sum -= nums[left++];
            } 
        }
        return (ans != INT_MAX) ? ans : 0;
    }
};

////////////////////////////

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        vector<int> sums = accumulatedSums(nums);
        int n = sums.size(), len = INT_MAX;
        for (int i = n - 1; i >= 0 && sums[i] >= s; i--) {
            int j = upper_bound(sums.begin(), sums.begin() + i, sums[i] - s) - sums.begin();
            len = min(len, i - j + 1);
        }
        return len == INT_MAX ? 0 : len;
    }
private:
    vector<int> accumulatedSums(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i < n + 1; i++) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }
        return sums;
    }
};