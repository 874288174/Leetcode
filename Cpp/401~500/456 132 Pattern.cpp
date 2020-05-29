class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> stk; //second, all of it is bigger than Third 
        for (int i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] < third) return true;
            while (!stk.empty() && nums[i] > stk.top()) {
                third = stk.top(); 
                stk.pop();
            }
            stk.push(nums[i]);
        }
        return false;
    }
};