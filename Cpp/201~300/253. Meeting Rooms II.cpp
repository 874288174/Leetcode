
/*
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> m;
        for (auto &v : intervals) {
            ++m[v[0]];
            --m[v[1]];
        }
        int rooms = 0, res = 0;
        for (auto &it : m) {
            res = max(res, rooms += it.second);
        }
        return res;
    }
};
*/

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] < rhs[0];
        };
        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> q;
        for (auto &v : intervals) {
            if (!q.empty() && q.top() <= v[0]) q.pop();
            q.push(v[1]);
        }
        return q.size();
    }
};

