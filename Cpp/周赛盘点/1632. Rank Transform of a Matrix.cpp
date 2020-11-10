class Solution {
public:
    int n, m; 
    vector<int> rows, cols;
    
    int find(vector<int> &ds, int i) {
        return ds[i] < 0 ? i : ds[i] = find(ds, ds[i]);
    }
    void process(vector<vector<int>> &matrix, vector<pair<int, int>> &crds) {
        vector<int> ds(n+m, -1);
        for (auto [i, j] : crds) {
            auto pi = find(ds, i), pj = find(ds, n + j);
            if (pi != pj) {
                ds[pi] = min({ds[pi], ds[pj], -max(rows[i], cols[j]) - 1});
                ds[pj] = pi;
            }
        }
        for (auto [i, j] : crds)
            matrix[i][j] = rows[i] = cols[j] = -ds[find(ds, i)];
    }
    
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        n = matrix.size(), m = matrix[0].size();
        rows.resize(n);
        cols.resize(m);
        vector<array<int, 3>> v;
        for (auto i = 0; i < n; ++i)
            for (auto j = 0; j < m; ++j)
                v.push_back({matrix[i][j], i, j});
        sort(begin(v), end(v), [](const auto &a, const auto &b){ return a[0] < b[0]; });
        vector<pair<int, int>> crds;
        int last_val = INT_MAX;
        for (auto &[val, i, j] : v) {
            if (val != last_val) {
                process(matrix, crds);
                last_val = val;
                crds.clear();
            }
            crds.emplace_back(i, j);
        }
        process(matrix, crds);
        return matrix;
    }
};