class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
            if (lhs[0] != rhs[0]) return lhs[0] < rhs[0];
            else return lhs[1] > rhs[1];
        };
        
        sort(intervals.begin(), intervals.end(), cmp);
        int pre = intervals[0][0], res = intervals.size();
        
        for (auto &v : intervals) {
            if (pre >= v[1]) --res;
            else pre = v[1];
        }
        return res;
    }
};