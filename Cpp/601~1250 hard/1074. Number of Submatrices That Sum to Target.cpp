class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size(), res = 0;
        vector<vector<int>> v{vector<int> (m, 0)};
        for (auto &t : matrix) {
            v.push_back(v.back());
            for (int i = 0; i < m; ++i) {
                v.back()[i] += t[i];
            }
        }
        
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                int sum = 0;
                unordered_map<int, int> mp{{0, 1}};
                for (int k = 0; k < m; ++k) {
                    sum += v[i][k] - v[j][k];
                    if (mp.count(sum-target)) res += mp[sum-target];
                    ++mp[sum];
                }
            }
        }
        return res;
    }
};