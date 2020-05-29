class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.empty()) return res;
        auto cmp = [](const vector<int> &a, const vector<int> &b){
                     return a[0] < b[0];};
        sort(intervals.begin(), intervals.end(), cmp); 
        res.push_back(intervals[0]);
        for (auto &v : intervals) {
           if (res.back()[1] < v[0]) res.push_back(v);
           else res.back()[1] = max(res.back()[1], v[1]);
        }
        return res;
    }
}