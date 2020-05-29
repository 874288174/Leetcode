class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size(), res = 0;
        vector<int> pre = points[0], cur;
        for (int i = 1; i < n; ++i) {
            cur = points[i];
            int dx = abs(cur[0]-pre[0]), dy = abs(cur[1]-pre[1]);
            res += min(dx, dy) + abs(dx-dy);
            pre = cur;
        }
        return res;
    }
};