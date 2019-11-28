class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n = prices.size(), res = 0;
       if (n < 2) return res;
       vector<int> f(n, 0), g(n, 0);
       for (int i = 1, buy = prices[0]; i < n; i++) {
           buy = min(buy, prices[i]);
           f[i] = max(f[i-1], prices[i]-buy);
       }
       for (int i = n-2, sell = prices[n-1]; i >= 0; i--) {
           sell = max(sell, prices[i]);
           g[i] = max(g[i], sell-prices[i]);
       }
       for (int i = 0; i < n; i++) res = max(res, f[i]+g[i]);
       return res;
    }
};

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int buy1 = INT_MIN, sale1 = 0, buy2 = INT_MIN, sale2 = 0;
       for (int &i : prices) {
           buy1 = max(buy1, -i);                        //left money after buy1
           sale1 = max(sale1, i + buy1);                //left money after sale1
           buy2 = max(buy2, sale1 - i);                 //left money after buy2
           sale2 = max(sale2, i + buy2);                //left money after sale2
       }
       return sale2;
    }
};
*/