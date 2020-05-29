class Solution {
public:    
    // fleury's algorithm or Hierholzer algorithm
    vector<string> findItinerary(vector<vector<string>> &tickets) {
        for (auto e : tickets)
            graph[e[0]].push(e[1]);
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
    
private:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> res;
        
    void dfs(string from) {
        auto &edges = graph[from];
        while (!edges.empty()) {
            string to = edges.top();
            edges.pop();
            dfs(to);
        }
        res.push_back(from);
    } 
};