class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        map<int, int> mp;
        vector<int> res;
        int n = intervals.size();
        for (int i = 0; i < n; ++i)
            mp[intervals[i][0]] = i;
        for (auto in : intervals) {
            auto pos = mp.lower_bound(in[1]);
            res.push_back(pos == mp.end() ? -1 : pos->second);
        }
        return res;
    }
};