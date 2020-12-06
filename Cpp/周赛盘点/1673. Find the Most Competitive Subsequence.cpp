class Solution {
public:
    vector<int> mostCompetitive(vector<int>& v, int k) {
        int n = v.size();
        vector<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && v[i] < stk.back() && n - i + stk.size() >= k+1) {
                stk.pop_back();
            }
            stk.push_back(v[i]);
        }
        stk.resize(k);
        return stk;
    }
};