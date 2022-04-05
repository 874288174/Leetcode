class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int m = queries.size(), n = rooms.size();
        vector<int> res(m);
        for (int i = 0; i < m; ++i) queries[i].push_back(i);
        sort(queries.begin(), queries.end(), [](const auto &a, const auto &b) {
            return a[1] > b[1]; 
        });
        
        sort(rooms.begin(), rooms.end(), [](const auto &a, const auto &b){
            return a[1] > b[1] || (a[1] == b[1] && a[0] < b[0]);
        });
        
        int ptr = -1;
        set<int> s;
        
        for (const auto &v : queries) {
            int i = v[2];
            while (ptr + 1 < n && rooms[ptr + 1][1] >= v[1]) {
                s.insert(rooms[++ptr][0]);
            }
            if (s.empty()) res[i] = -1;
            else {
                int p = v[0];
                auto it = s.lower_bound(p);
                if (it != s.begin() && (it == s.end() || p - *prev(it) <= *it - p))
                    res[i] = *prev(it);
                else res[i] = *it;
            }
        }
        return res;
    }
};