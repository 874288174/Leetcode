class Solution {
public:
    string rearrangeString(string str, int k) {
        if (k == 0) return str;
        string res;
        int len = str.size();
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;
        for (auto i : str) ++mp[i];
        for (auto i : mp) pq.emplace(i.second, i.first);
        
        while (!pq.empty()) {
            vector<pair<int, char>> v;
            int cnt = min(k, len);
            for (int i = 0; i < cnt; ++i) {
                if (pq.empty()) return "";
                auto t = pq.top(); 
                pq.pop();
                if (--t.first > 0) v.push_back(t);
                res += t.second;
                --len;
            }
            for (auto a : v) pq.push(a);
        }
        return res;
    }
};