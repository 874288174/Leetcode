class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if (costs.empty()) return 0;
        int min1 = 0, min2 = 0, idx = -1;
        for (auto &cost : costs) {
            int m1 = INT_MAX, m2 = m1, id = -1;
            for (int j = 0; j < cost.size(); j++) {
                int temp = cost[j] + (j == idx ? min2 : min1);
                if (temp < m1) {
                    m2 = m1; m1 = temp; id = j;
                } else if (temp < m2) {
                    m2 = temp;
                }
            }
            min1 = m1; min2 = m2; idx = id;
        }
        return min1;
    }
};