class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        int n = nums.size();
        if (n <= 1) return;
        for (int i = 1; i < n; ++i) {
            if (i%2 && nums[i] < nums[i-1] || !(i%2) && nums[i] > nums[i-1]) {
                swap(nums[i], nums[i-1]);
            }
        }
    }
};