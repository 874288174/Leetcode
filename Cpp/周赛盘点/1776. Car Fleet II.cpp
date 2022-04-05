class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        vector<double> res(cars.size());
        stack<int> stk;
        for(int i = cars.size()-1; i >= 0; i--) {
            while (!stk.empty()) {
                if (cars[stk.top()][1] >= cars[i][1]) stk.pop();
                else {
                    if (res[stk.top()] < 0) break;
                    double d = res[stk.top()]*(cars[i][1]-cars[stk.top()][1]);
                    if (d > cars[stk.top()][0]-cars[i][0]) break;
                    else stk.pop();
                }
            }
            if (stk.empty()) res[i] = -1;
            else res[i] = double(cars[stk.top()][0]-cars[i][0]) / (cars[i][1]-cars[stk.top()][1]);
            stk.push(i);
        }
        return res;
    }
};