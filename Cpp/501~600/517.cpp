class Solution {
public:
    using pii = pair<int,int>;
    int findMaximizedCapital(int k, int W, vector<int>& p, vector<int>& c) {
        vector<pii> v;
        for (int i = 0 ; i < p.size(); ++i) {
            if (p[i] > 0)
               v.emplace_back(p[i], c[i]);
        }
        sort(v.begin(), v.end(), [&](const pii &a, const pii &b) {
            return a.second < b.second;
        });
        
        priority_queue<int> pq;
        
        size_t i = 0;
        
        while (k--) {
            while (i < v.size() && v[i].second <= W)     
                pq.push(v[i++].first);
            if (!pq.empty()) {
                W += pq.top();
                pq.pop();
            }
        }
        return W;
    }
};