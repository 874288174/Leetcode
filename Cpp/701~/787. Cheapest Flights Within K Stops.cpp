class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        using ti = tuple<int,int,int>;
        vector<vector<pair<int,int>>> vp(n);
        for(const auto&f : flights)   vp[f[0]].emplace_back(f[1],f[2]);
        priority_queue<ti, vector<ti>, greater<ti>>pq;
        pq.emplace(0, src, K+1);
        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();
            if (u == dst)  return cost;
            if (!stops)  continue;
            for (auto to : vp[u]){
                auto [v, w] = to;
                pq.emplace(cost+w, v, stops-1);
            }
        }
        return -1;
    }
};
/*
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    //bellman ford.
    //just run it k+1 iterations.
        const int inf = 1e8; 
        vector<int> dist(n, inf);
        dist[src] = 0;
        for(int k = 0; k <= K; ++k){
            vector<int> newDist(dist);
            for(auto e : flights) {
                newDist[e[1]] = min(newDist[e[1]], dist[e[0]] + e[2]);
            }
            dist = newDist;
        }
        return dist[dst] == inf ? -1 : dist[dst];
    }
};
*/