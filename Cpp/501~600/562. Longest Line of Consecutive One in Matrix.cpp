class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.empty()) return 0;
        int n = M.size(), m = M[0].size(), res = 0;
        vector<int> v(m, 0), a(m, 0), b(m, 0);
        for (int i = 0; i < n; ++i) {
            int h = 0;
            vector<int> d = a, anti_d= b; 
            for (int j = 0; j < m; ++j) {
                if (!M[i][j]) h = v[j] = a[j] = b[j] = 0;
                else {
                    if (j != 0) a[j] = d[j-1] + 1;
                    if (j != m-1) b[j] = anti_d[j+1] + 1;
                    res = max({res, ++h, ++v[j], a[j], b[j]});
                }
            }
        }
        return res;
    }
};