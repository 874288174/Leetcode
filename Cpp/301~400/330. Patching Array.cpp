class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int cnt = 0, i = 0;
        long long maxNum = 1;
        while (maxNum <= n) {
            if (i < nums.size() && nums[i] <= maxNum)
                maxNum += nums[i++];
            else {
                maxNum *= 2;
                cnt++;
            }
        }
        return cnt;
    }
};