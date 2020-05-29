class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        int n = nums.size(), temp = n-1;
        for (int i = n-1; i >= 0; --i) {
            int j = i + nums[i];
            if (j >= temp) {
                temp = i;
            }
        }
        return temp == 0;
    }
};