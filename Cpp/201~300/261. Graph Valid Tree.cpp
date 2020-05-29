class Solution {
public:    
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;
        fa.resize(n, -1);
        for (auto a : edges) {
            int x = find(a[0]), y = find(a[1]);
            if (x == y) return false;
            else fa[x] = y;
        }
        return true;
    }
private:
    vector<int> fa;
    int find(int i) {
        return (fa[i] == -1) ? i : (fa[i] = find(fa[i]));
    }
};



class Solution {
public: 
        bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> v(n, -2);
        vector<vector<int>> g(n);
        for (auto &edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        if (!dfs(g, v, 0, -1)) return false;
        for (auto a : v) {
            if (a == -2) return false;
        }
        return true;
    }
    bool dfs(vector<vector<int>> &g, vector<bool> &v, int cur, int pre) {
        if (v[cur] != -2) return false;
        v[cur] = pre;
        for (auto a : g[cur]) {
            if (a != pre) {
                if (!dfs(g, v, a, cur)) return false;
            }
        }
        return true;
    }
};
