class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end());
        int res = 1, high = INT_MAX;
        for (auto &pnt : points) {
            if (pnt[0] > high) {
                high = pnt[1];
                res++;
            }
            high = min(high, pnt[1]);
        }
        return res;
    }
};
