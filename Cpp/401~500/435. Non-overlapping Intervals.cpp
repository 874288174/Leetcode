class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        stack<vector<int>> stk;
        int i = 0, n = intervals.size();
        while (i < n) {
            auto &v = intervals[i];
            if (stk.empty() || stk.top()[1] <= v[0]) {
                stk.push(v);
                i++;
            }
            else if (stk.top()[1] > v[1]) stk.pop();
            else i++;
        }
        return n - stk.size();
    }
};