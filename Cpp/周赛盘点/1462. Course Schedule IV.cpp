class Solution {
public:
    using bits = bitset<100>; 

    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);

        for(auto v: prerequisites) {
            g[v[0]].emplace_back(v[1]);
        }
        vector<bits> cache(n, 0);

        function<bits(int i)> dfs = [&](int i) {
            if (cache[i][i]) return cache[i];
            cache[i][i] = true;
            for (int v: g[i])  cache[i] |= dfs(v);
            return cache[i];
        };
        for(int i = 0; i < n; i++) dfs(i);
        vector<bool> res;
        for(auto &q: queries)  res.emplace_back(cache[q[0]][q[1]]);
        return res;
    }
};