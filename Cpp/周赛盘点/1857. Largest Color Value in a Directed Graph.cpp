class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int> deg(n);
        vector<vector<int>> adj(n);
        for (auto &edge : edges) {
            int u = edge[0], v = edge[1];
            deg[v]++;
            adj[u].emplace_back(v);
        }
        
        queue<int> q;
        for (int i = 0; i < n; ++i) if (!deg[i]) q.push(i);
        
        
        vector<int> topo;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.emplace_back(u);
            for (int v : adj[u]) {
                if (--deg[v] == 0)
                    q.push(v);
            }
        }
        
        if (topo.size() != n) return -1;
        
        int res = 0;
        for (auto color : set<char> (colors.begin(), colors.end())) {
            vector<int> dp(n);
            for (int i = n - 1; i >= 0; --i) {
                int u = topo[i];
                for (int v : adj[u])
                    dp[u] = max(dp[u], dp[v]);
                if (colors[u] == color) dp[u]++;
                res = max(res, dp[u]);
            }
        }
        return res;
    }
};