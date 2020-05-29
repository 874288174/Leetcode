class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0, b = 0, n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0)    a = max(a+nums[i], b);
            else    b = max(a, b+nums[i]);
        } 
        return max(a, b);
    }   
};

/*
class Solution {
public:
    int rob(vector<int>& nums) {
        int res[2] = {0, 0};   
        for (auto &i : nums) {
            int temp = res[1];
            res[1] = res[0] + i;  
            res[0] = max(res[0], temp);
        }
        return max(res[0], res[1]);
    }
};
*/