class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dis(n, vector<int> (n, 1e9));
        vector<int> neig(n, 0);
        for (auto &v : edges) {
            dis[v[0]-1][v[1]-1] = dis[v[1]-1][v[0]-1] = 1;
            neig[v[0]-1] |= 1 << (v[1]-1);
            neig[v[1]-1] |= 1 << (v[0]-1);
        }
        for (int i = 0; i < n; ++i) dis[i][i] = 0;
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        vector<bool> vis(1<<n, false);
        vector<int> res(n-1, 0);
        for (int k = 1; k < (1 << n); ++k) {
            if (__builtin_popcount(k) == 1) vis[k] = true;
            if (!vis[k]) continue;
            int t = 0;
            for (int i = 0; i < n; ++i) {
                if (k & (1 << i)) {
                    t |= neig[i];  
                }
            }
            
            for (int i = 0; i < n; ++i) {
                if ((t & (1 << i)) && (k & (1 << i)) == 0) {
                    vis[k | (1 << i)] = true;
                }
            }
            
            int d = 0;
            for (int i = 0; i < n; ++i) {
                if ((k & (1 << i))) {
                    for (int j = 0; j < n; ++j) {
                        if ((k & (1 << j))) {
                            d = max(d, dis[i][j]);
                        }
                    }
                }
            }
            if (d == 0) continue;
            ++res[d-1];
        }
        return res;
    }
};







class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        int INF = n; // Since cities form a tree so maximum distance between 2 cities always < n
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (auto& e : edges) 
            dist[e[0]-1][e[1]-1] = dist[e[1]-1][e[0]-1] = 1;
        
        for (int k = 0; k < n; k++)
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        
        vector<int> ans(n - 1, 0);
        for (int state = 0; state < (1 << n); state++) {
            int d = maxDistance(state, dist, n);
            if (d > 0) ans[d - 1] += 1;
        }
        return ans;
    }
    
    int maxDistance(int state, vector<vector<int>>& dist, int n) {
        int cntEdge = 0, cntCity = 0, maxDist = 0;
        for (int i = 0; i < n; i++) {
            if (((state >> i) & 1) == 0) continue; // Skip if city `i` not in our subset
            cntCity += 1;
            for (int j = i + 1; j < n; j++) {
                if (((state >> j) & 1) == 0) continue; // Skip if city `j` not in our subset
                cntEdge += dist[i][j] == 1;
                maxDist = max(maxDist, dist[i][j]);
            }
        }
        if (cntEdge != cntCity - 1) return 0; // Subset form an invalid subtree!
        return maxDist;
    }
};












class Solution {
public:
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto& e : edges) {
            graph[e[0]-1].push_back(e[1]-1);
            graph[e[1]-1].push_back(e[0]-1);
        }
        vector<int> ans(n - 1, 0);
        for (int state = 1; state < (1 << n); state++) {
            int d = maxDistance(state, graph, n);
            if (d > 0) ans[d - 1] += 1;
        }
        return ans;
    }
    
    int maxDistance(int state, vector<vector<int>>& graph, int n) {
        int anyNode = 0, cntCity = 0;
        for (int i = 0; i < n; i++) if ((state >> i) & 1) {
            anyNode = i;
            cntCity += 1;
        }
        auto [farthestNode, _, visitedSize] = bfs(anyNode, state, graph, n);
        if (visitedSize < cntCity) return 0; // Can't visit all nodes of the tree -> Invalid tree
        auto [_ig1, dist, _ig2] = bfs(farthestNode, state, graph, n);
        return dist;
    }
    
    tuple<int, int, int> bfs(int src, int state, vector<vector<int>>& graph, int n) {
        unordered_set<int> visited{src};
        queue<pair<int,int>> q;
        q.push({src, 0});
        int farthestNode = -1, farthestDist = 0;
        while(!q.empty()){
            auto [u, d] = q.front(); q.pop();
            farthestNode = u, farthestDist = d;
            for (int v : graph[u]){
                if (visited.find(v) == visited.end() && (state >> v) & 1){
                    q.push({v, d + 1});
                    visited.insert(v);
                }
            }
        }
        return make_tuple(farthestNode, farthestDist, visited.size());
    }
};