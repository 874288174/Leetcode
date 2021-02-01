class Solution {
public:
    vector<vector<int>> matrixRankTransform(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        map<int, vector<int>> mp;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                mp[matrix[i][j]].push_back(i*n + j);
            }
        }
        
        vector<int> rank(m + n, 0);
        vector<vector<int>> res(m, vector<int>(n));
        
        for (auto &it: mp) {
            vector<int> fa(m + n, 0);
            iota(begin(fa), end(fa), 0);
            
            auto &v = it.second;
            for (auto &a : v) {
                int i = a / n, j = a % n;
                int r1 = find(fa, i), r2 = find(fa, j + m);
                fa[r1] = r2;
                rank[r2] = max(rank[r1], rank[r2]); 
            }
            
            auto rank2 = rank;
            for (auto & a: v) {
                int i = a / n, j = a % n;
                int r = find(fa, i);
                res[i][j] = rank2[i] = rank2[j + m] = rank[r] + 1;
            }
            rank = move(rank2);
        }
        return res;
    }
    
    int find(vector<int> & fa, int x) {
        return fa[x] == x ? fa[x] : fa[x] = find(fa, fa[x]);
    }
};