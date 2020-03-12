class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        //dpi 为含i个0最长的连续一
        int n = nums.size(), res = 0, dp0 = 0,dp1 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i]) {
                ++dp0; 
                ++dp1;
            }
            else {
                dp1 = dp0+1;
                dp0 = 0;
            }
            res = max(res, max(dp0, dp1));
        }
        return res;
    }
};