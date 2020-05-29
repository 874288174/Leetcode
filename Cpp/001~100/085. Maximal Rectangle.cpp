class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        int res = 0, n = matrix[0].size(), m = matrix.size();
        vector<int> v(n+1,0);
        for (auto &u : matrix) {
            for(int j = 0; j < n; j++) {
                if (u[j] == '1') v[j]++;
                else v[j] = 0;
            }
            res = max(res, largestRectangleArea(v));
        }
        return res;
    }
    
private:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> stk;
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