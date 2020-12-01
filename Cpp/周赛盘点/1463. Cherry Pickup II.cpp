class Solution {
public:
    int cherryPickup(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        int f[2][n][n];
        int res = 0, p = 0;
        memset(f, -1, sizeof(f));
        f[0][0][n - 1] = v[0][0] + v[0][n-1];
        for (int i = 1; i < m; i++) {
            auto &pre = f[p], &cur = f[p^1];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    int value = (j == k) ? v[i][j] : v[i][j] + v[i][k];
                    for (int col1 = j-1; col1 <= j+1; col1++) {
                        for (int col2 = k-1; col2 <= k+1; col2++) {
                            if (col1>=0 && col1<n && col2>=0 && col2<n && pre[col1][col2]>=0) {
                                cur[j][k] = max(cur[j][k], pre[col1][col2] + value);
                                if (i == m-1) res=max(res, cur[j][k]);
                            }
                        }
                    }
                }
            }
            p ^= 1;
        }
        return res;
    }
};
