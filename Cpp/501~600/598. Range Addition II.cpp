class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (auto &v : ops) {
            m = min(m, v[0]);
            n = min(n, v[1]);
        }
        return n*m;
    }
};