class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& v, int k) {
        int n = v.size(), m = v[0].size();
        if (n > m) {
            v = rotate(v);
            swap(n, m);
        }
        int res = INT_MIN;
        for (int i = 0; i < n; ++i) {
            vector<int> S(m, 0);
            for (int j = i; j < n; ++j) {
                for (int a = 0; a < m; ++a) S[a] += v[j][a];
                set<int> Myset{0};
                int sum = 0;
                for (auto a : S) {
                    sum += a;
                    auto it = Myset.lower_bound(sum-k);
                    if (it != Myset.end()) {
                        res = max(res, sum - *it);
                    } 
                    Myset.insert(sum);
                }
            }
        }
        return res;
    }
private:
    vector<vector<int>> rotate(vector<vector<int>> &v) {
        int n = v.size(), m = v[0].size();
        vector<vector<int>> res(m, vector<int> (n));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res[j][i] = v[i][j];
            }
        }
        return res;
    }
};