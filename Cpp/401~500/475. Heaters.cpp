class Solution {
public:
    int findRadius(vector<int>& house, vector<int>& heat) {
        sort(heat.begin(), heat.end());
        int minRadius = 0, n = house.size();
        for (int i = 0; i < n; ++i) {
            auto big = lower_bound(heat.begin(), heat.end(), house[i]);
            int curRadius = INT_MAX;
            if (big != heat.end()) curRadius = *big - house[i];
            if (big != heat.begin()) {
                auto small = big - 1;
                curRadius = min(curRadius, house[i] - *small);
            }
            minRadius = max(minRadius, curRadius);
        }
        return minRadius;
    }
};
