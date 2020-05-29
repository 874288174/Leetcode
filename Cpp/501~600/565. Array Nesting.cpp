class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size(), cnt = 0, res = 0;
        for (int i = 0; i < n; ++i) if (nums[i] >= 0) {    
            int j = i;
            while (nums[j] >= 0) {
                int t = nums[j];
                nums[j] = -1;
                j = t; 
                cnt++;
            }
            res = max(res, cnt);
            cnt = 0;
        }
        return res;
    }
};