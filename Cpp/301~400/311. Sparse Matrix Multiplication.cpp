class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>> &A, vector<vector<int>> &B) {
        int n = A.size(), l = B.size(), m = B[0].size();
        vector<vector<int>> res(n, vector<int> (m, 0));
        vector<pair<int, int>> v[l];
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < m; j++) if (B[i][j]) {
                v[i].push_back({j, B[i][j]});
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int k = 0; k < l; ++k) if (A[i][k]) {    
                for (auto &pii : v[k]) {
                    res[i][pii.first] += A[i][k] * pii.second;   
                }
            }
        }
        return res;
    }
};