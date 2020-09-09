class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> g(n);
        vector<int> indegree(n, 0);
        for(auto v: prerequisites) {
            g[v[0]].emplace_back(v[1]);
            ++indegree[v[1]];
        }
        vector<bitset<100> > cache(n, 0);  // n <= 100

        function<bitset<100>(int)> dfs1462 = [&](int i){

            if(g[i].empty())  {bitset<100> b(0); b[i] = true; return b; }  // outdegree[i] == 0
            if(cache[i] != bitset<100>(0)) return cache[i];

            cache[i][i] = true;
            for(int v: g[i])  cache[i] |= dfs1462(v);
            return cache[i];
        };
        for(int i=0; i<n; i++)
            if(indegree[i]==0)
                dfs1462(i);
        vector<bool> res(queries.size(), false);
        int i=0;
        for(auto &q: queries)  res[i++] = bool(cache[q[0]][q[1]]);
        return res;
    }
};