class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] != rhs[0] ? lhs[0] < rhs[0] : lhs[1] < rhs[1];
        });
        int res = 1, low = INT_MIN, high = INT_MAX;
        for (auto &pnt : points) {
            if (pnt[0] > high) {
                low = pnt[0], high = pnt[1];
                res++;
            }
            high = min(high, pnt[1]);
        }
        return res;
    }
};