class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        auto cmp = [](const vector<int> &lhs, const vector<int> &rhs) {
            return lhs[1] - lhs[0] < rhs[1] - rhs[0];
        };
        sort(tasks.begin(), tasks.end(), cmp);
        int res = 0;
        for (auto &v : tasks) res = max(res+v[0], v[1]);
        return res;
    }
};