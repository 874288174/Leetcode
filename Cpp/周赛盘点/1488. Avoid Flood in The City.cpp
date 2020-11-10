class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);
        map<int, int> mp; 
        set<int> st;
        for (int i = 0; i < n; ++i) {
            if (rains[i] == 0) st.insert(i);
            else if (mp.count(rains[i])) {
                auto it = st.upper_bound(mp[rains[i]]);
                if (it == st.end()) return {};
                
                res[*it] = rains[i];
                st.erase(it);
                mp[rains[i]] = i;
            }
            else mp[rains[i]] = i;
        }
        if (st.empty()) return res;
        for (auto it = st.rbegin(); it != st.rend(); ++it) {
            res[*it] = 1;
        }
        return res;
    }
};

