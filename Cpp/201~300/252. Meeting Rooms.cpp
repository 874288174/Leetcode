class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false;
            }
        }
        return true;
    }
};