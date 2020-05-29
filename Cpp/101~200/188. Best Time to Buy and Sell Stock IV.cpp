class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        int N = prices.size();
        if (k >= N) return maxProfit(prices);
        vector<int> buy(k + 1, INT_MIN);
        vector<int> sell(k + 1, 0);
        //buy代表交易k次且付钱买入一件
        for (int i = 0; i < N; ++i) {
            for (int j = 1; j <= k; ++j) {
                buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return max(buy[k], sell[k]);
    }
private:
    int maxProfit(vector<int>& prices) {
        int Buy = INT_MAX, res = 0;
        for (auto &Sell : prices) {
            if (Sell > Buy)   res += Sell-Buy;
            Buy = Sell;
        }
        return res;
    }
};