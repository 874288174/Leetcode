class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& loc) {
        vector<double> angs;
        int max_points = 0, overlap = 0;
        for (auto &p : points) {
            if (p[1] == loc[1] && p[0] == loc[0])
                ++overlap;
            else
                angs.push_back(atan2(p[1] - loc[1], p[0] - loc[0]) * 180 / M_PI);
        }
        sort(begin(angs), end(angs));
        int n = angs.size();
        auto getAngle = [&](int i) {
            return 360*(i >= n) + angs[i%n];
        };
        for (int i = 0, j = 0; i < n * 2; ++i) {
            while (getAngle(i) - getAngle(j) > angle) ++j;
            max_points = max(max_points, i-j+1);
        }
        return max_points + overlap;
    }
};