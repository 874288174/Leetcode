class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        if (S == T) return 0;
        
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < routes.size(); ++i)
            for (int j : routes[i])
                mp[j].push_back(i);
        
        
        queue<int> q;
        q.emplace(S);
        unordered_set<int> vis{S};
        
        int cnt = 0;
        
        while (!q.empty()) {
            ++cnt;
            int sz = q.size();
            while (sz--) {
                auto stop = q.front();
                q.pop();
                for (int i : mp[stop]) {
                    for (int j : routes[i]) {
                        if (j == T) return cnt;
                        if (vis.find(j) == vis.end()) {
                            vis.insert(j);
                            q.emplace(j);
                        }
                    }
                    routes[i].clear();
                }
            }
        }
        return -1;
    }
};