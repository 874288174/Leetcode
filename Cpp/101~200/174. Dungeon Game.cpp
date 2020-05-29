class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon[0].size();
        vector<int> f(m, INT_MAX);
        for (int i = n-1; i >= 0; --i) {
            for (int j = m-1; j >= 0; --j) {
                if (i == n-1 && j == m-1) {
                    f[j] = max(1, 1-dungeon[i][j]);
                }else if (j == m-1) {
                    f[j] = max(f[j]-dungeon[i][j], 1);
                }else {
                    f[j] = max(min(f[j], f[j+1])-dungeon[i][j], 1);
                }
            }
        }
        return f[0];
    }
};