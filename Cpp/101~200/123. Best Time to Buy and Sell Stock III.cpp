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
