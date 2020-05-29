class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<bool> v(n, false);
        for (auto &i : edges) {
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        for (int i = 0; i < n; i++) if (!v[i]) {
            dfs(i, g, v);
            res++;
        }
        return res;
    }
private:
    int res = 0;
    void dfs(int i, vector<vector<int>> &g, vector<bool> &v) {
        v[i] = true;
        for (auto &j : g[i]) if (!v[j]) {
            dfs(j, g, v);
        }
    }
};