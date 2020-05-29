class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2) return n ? nums[0] : 0;
        return max(rob(nums, 0, n - 1), rob(nums, 1, n));
    }
private:
    int rob(vector<int>& nums, int l, int r) {
        int pre = 0, cur = 0;
        for (int i = l; i < r; i++) {
            int temp = max(pre + nums[i], cur);
            pre = cur;
            cur = temp;
        }
        return cur;
    }
};
