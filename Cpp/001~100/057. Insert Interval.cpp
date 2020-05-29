class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, 
vector<int>& newInterval) {
        auto it = intervals.begin();
        while (it != intervals.end()) {
            if ((*it)[1] < newInterval[0]) it++;
            else if ((*it)[0] > newInterval[1]) {
                intervals.insert(it, newInterval);
                return intervals;
            } else {
                newInterval[0] = min(newInterval[0], (*it)[0]);
                newInterval[1] = max(newInterval[1], (*it)[1]);
                it = intervals.erase(it);
            }
        }
        intervals.insert(intervals.end(), newInterval);
        return intervals;
    }
};



class Solution {
public:
vector<vector<int>> insert(vector<vector<int>>& intervals, 
vector<int>& newInterval) {
        auto cmp = [] (const vector<int> &lhs, const vector<int> &rhs) { 
            return lhs[1] < rhs[0]; 
        };
        auto range = equal_range(intervals.begin(), intervals.end(), newInterval, cmp);
        auto p = range.first, q = range.second;
        if (p == q)  intervals.insert(p, newInterval);
        else {
            q--;
            (*q)[0] = min(newInterval[0], (*p)[0]);
            (*q)[1] = max(newInterval[1], (*q)[1]);
            intervals.erase(p, q);
        }
        return intervals;
    }
};
