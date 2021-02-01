class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[0] == rhs[0] ? lhs[1] < rhs[1] : lhs[0] < rhs[0];
        });
        int res = 0, end = INT_MIN;
        for (auto &v : pairs) {
           if (v[0] > end) {
               res++;
               end = v[1];
           }
           else end = min(end, v[1]);
        }
        return res;
    }
};