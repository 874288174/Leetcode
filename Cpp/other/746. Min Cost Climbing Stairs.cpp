class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int f0 =  cost[0], f1 = cost[1];
        cost.push_back(0);
        for (int i = 2; i < cost.size(); ++i) {
           int temp = f1;
           f1 = min(f0, f1) + cost[i];
           f0 = temp;
        }
        return f1;
    }
};