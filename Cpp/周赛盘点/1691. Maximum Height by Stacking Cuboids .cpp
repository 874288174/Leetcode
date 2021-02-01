class Solution {
public:
    int dp[105][3];

    int maxHeight(vector<vector<int>>& cuboids) {
        int res = 0;
        auto cmp = [](const auto &a, const auto &b) {
            return a[0]*a[1]*a[2] < b[0]*b[1]*b[2];
        };
        sort(cuboids.begin(), cuboids.end(), cmp);
        for (int i =0; i < cuboids.size(); ++i) {
            for (int k = 0; k < 3; ++k) {
                dp[i][k] = cuboids[i][k];

                int w0 = cuboids[i][(k+1)%3], l0 = cuboids[i][(k+2)%3];
                if (w0 > l0) swap(w0, l0);

                for (int j = 0; j < i; ++j) {
                    for (int kk = 0; kk < 3; ++kk) {
                        if (cuboids[i][k] < cuboids[j][kk]) continue;
                        int w1 = cuboids[j][(kk+1)%3], l1 = cuboids[j][(kk+2)%3];
                        if (w1 > l1) swap(w1, l1);
                        if (l1 <= l0 && w1 <= w0) {
                            dp[i][k] = max(dp[i][k], dp[j][kk] + cuboids[i][k]);
                        }
                    }
                }
                res = max(res, dp[i][k]);
            }
        }
        return res;
    }
};