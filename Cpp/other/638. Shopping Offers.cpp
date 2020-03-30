class Solution {
public:
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int res = inner_product(price.begin(), price.end(), needs.begin(), 0);
        for (const auto &offer : special) {
            if (offer.back() >= res) continue;
            vector<int> r;
            if (!Sub(needs, offer, r)) continue;
            res = min(res, offer.back() + shoppingOffers(price, special, r));
        }
        return res;
    }
    bool Sub(const vector<int>& needs, const vector<int>& offer, vector<int>& res) {
        int n = needs.size();
        res.resize(n);
        for (int i = 0; i < n; ++i) {
            if (offer[i] > needs[i]) return false;
            res[i] = needs[i] - offer[i];
        }
        return true;
    }
};