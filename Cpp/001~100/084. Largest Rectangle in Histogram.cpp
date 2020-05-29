class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
        heights.push_back(0);
        int res = 0, n = heights.size();
        for (int i = 0; i < n; i++) {
            while(!stk.empty() && heights[i] <= heights[stk.top()]) {
                int h = heights[stk.top()];
                stk.pop();
                res = max(res, 
                          h*(stk.empty() ? i : i-stk.top()-1));
            }
            stk.push(i);
        }
        return res;
    }
};