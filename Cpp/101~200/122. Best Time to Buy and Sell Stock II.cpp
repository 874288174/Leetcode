class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Buy = INT_MAX, res = 0;
        for (auto &Sell : prices) {
            if (Sell > Buy)   res += Sell-Buy;
            Buy = Sell;
        }
        return res;
    }
};