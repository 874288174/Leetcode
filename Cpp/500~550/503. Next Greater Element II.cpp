class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> stk;
        int n = nums.size();
        vector<int> res(n, -1);
        for(int k = 0; k < 2; k++) {
            for (int i = 0; i < n; i++) {
                while (!stk.empty() && nums[stk.top()] < nums[i]) {
                    res[stk.top()] = nums[i];
                    stk.pop();
                }           
                stk.push(i);
            }
        }
        return res;
    }
};