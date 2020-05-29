class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int res = 1, n = nums.size(), i = 0;
        while (i < n) {
            int farest = i+nums[i], temp = farest;
            if (farest >= n-1) return res;
            else for (int k = i+1; k <= farest; k++) {
                if (k+nums[k] > temp) temp = k + nums[i = k];
            }
            res++;
        }
        return res;
    }
};