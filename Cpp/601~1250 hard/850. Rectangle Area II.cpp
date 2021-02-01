class Solution {
public:
    int rectangleArea(vector<vector<int>>& rect) {
        vector<int> X, Y;
        for (auto v : rect) {
            X.push_back(v[0]); X.push_back(v[2]);
            Y.push_back(v[1]); Y.push_back(v[3]);
        }
        sort(X.begin(), X.end());
        sort(Y.begin(), Y.end());

        int n = X.size(), m = Y.size();
        vector<vector<bool>> t(n, vector<bool> (m, false));
        
        for (auto v : rect) {
            int x0 = lower_bound(X.begin(), X.end(), v[0]) - X.begin();
            int y0 = lower_bound(Y.begin(), Y.end(), v[1]) - Y.begin();
            int x1 = lower_bound(X.begin(), X.end(), v[2]) - X.begin();
            int y1 = lower_bound(Y.begin(), Y.end(), v[3]) - Y.begin();

            for (int i = x0; i < x1; ++i) {
                for (int j = y0; j < y1; ++j) {
                    t[i][j] = true;
                }
            }
        }
        
        long long res = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (t[i][j]) {
                    long long x = X[i+1] - X[i];
                    long long y = Y[j+1] - Y[j];
                    res = (res + x*y) % mod;
                }
            }
        }
        return static_cast<int> (res);
    }
};