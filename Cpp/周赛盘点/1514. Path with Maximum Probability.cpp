class Solution {
public:
    using pdi = pair<double, int>;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& pro, int start, int end) {
        vector<vector<pdi>> g(n);
        for(int i = 0; i < edges.size(); i++) {
            g[edges[i][0]].emplace_back(pro[i], edges[i][1]);
            g[edges[i][1]].emplace_back(pro[i], edges[i][0]);   
        }
        vector<bool> seen(n, false);
        
        priority_queue<pdi> pq;
        pq.emplace(1.0, start);
        
        vector<double> mx(n, 0.0);
        mx[start] = 1.0;
        
        while (!pq.empty()) {
            auto [proba, node] = pq.top();
            pq.pop();
            if (!seen[node]) {
                seen[node] = true;
                for (const auto &[i, j] : g[node]) {
                    if (mx[j] < i*proba) {
                        mx[j] = i*proba;
                        pq.emplace(mx[j],j);
                    }
                }
            }
        }
        return mx[end];
    }
};
