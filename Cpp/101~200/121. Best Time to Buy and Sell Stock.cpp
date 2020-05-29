class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Min = INT_MAX, res = 0;
        for (auto &i : prices) {
            if (i < Min) Min = i;
            else res = max(res, i-Min);
        }
        return res;
    }
};