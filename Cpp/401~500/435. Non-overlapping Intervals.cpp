class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size(), end = intervals[0][0], res = n;
        for (const auto &v : intervals) {
            if (end <= v[0]) {
                end = v[1];
                --res;
            }
            else end = min(end, v[1]);
        }
        return res;
    }
};
