class Solution {
public:
    int leastBricks(vector<vector<int>> &wall) {
        unordered_map<int, int> m;
        int res = 0, sz = wall.size();
        for (int i = 0; i < sz; i++) {
            for (int j = 0, sum = 0; j < wall[i].size() - 1; j++) {
                res = max(res, ++m[sum += wall[i][j]]);
            }
        }
        return sz - res;
    }
};