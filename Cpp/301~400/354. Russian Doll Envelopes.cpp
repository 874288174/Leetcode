class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        vector<int> dp;
        for (auto &v : envelopes) {
            auto iter = lower_bound(dp.begin(), dp.end(), v[1]);
            if (iter == dp.end()) dp.push_back(v[1]);
            else if (v[1] < *iter) *iter = v[1];
        }
        return dp.size();
    }
};