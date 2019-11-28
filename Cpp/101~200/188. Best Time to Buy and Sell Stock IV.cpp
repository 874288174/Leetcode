class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        if (prices.empty()) return 0;
        int n = prices.size();
        if (k >= n) return maxProfit(prices);
        vector<int> g(k+1, 0), l(k+1, 0);
        for (int i = 1; i < n; i++) {
            int diff = prices[i] - prices[i-1];
            for (int j = k; j >= 1; j--) {
                l[j] = max(g[j-1] + max(diff, 0), l[j] + diff);
                g[j] = max(g[j], l[j]);
            }
        }
        return g[k];
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
}