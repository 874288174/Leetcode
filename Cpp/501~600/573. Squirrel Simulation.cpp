class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int sum = 0;
        int d = INT_MAX;
        for (const auto &v : nuts) {
            int d0 = abs(v[0] - tree[0]) + abs(v[1] - tree[1]);
            int d1 = abs(v[0]-squirrel[0]) + abs(v[1]-squirrel[1]);
            sum += 2*d0;
            d = min(d, d1-d0);
        }
        return sum + d;
    }
};