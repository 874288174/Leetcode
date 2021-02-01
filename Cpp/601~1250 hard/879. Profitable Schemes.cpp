class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<ll>> pre(n+1, vector<ll>(minProfit+1, 0));
        pre[0][0] = 1;
        for (int i = 0; i < group.size(); ++i) {
            vector<vector<ll>> cur = pre;
            for (int a = 0, aa = group[i]; aa <= n; ++a, ++aa) {
                for (int b = 0; b <= minProfit; ++b) {
                    int bb = min(b+profit[i], minProfit);
                    cur[aa][bb] = (cur[aa][bb] + pre[a][b]) % mod;   
                }
            }
            pre = std::move(cur);
        }
        ll res = 0;
        for (int i = 0; i <= n; ++i) res = (res + pre[i][minProfit]) % mod;
        return static_cast<int> (res);
    }
};