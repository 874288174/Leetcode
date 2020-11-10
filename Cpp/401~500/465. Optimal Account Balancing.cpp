class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> m;
        for (const auto &t : transactions) {
            m[t[0]] -= t[2];  m[t[1]] += t[2];
        }
        vector<int> v;
        for_each(m.begin(), m.end(), [&v](auto it){if (it.second) v.emplace_back(it.second);});
        
        helper(v, 0, v.size(), 0);
        return res;
    }
    
    int res = INT_MAX;

    void helper(vector<int> &v, int start, int n, int cnt) {
        if (cnt >= res) return;
        while (start < n && v[start] == 0) ++start;
        if (start == n) res = min(res, cnt);
        else for (int i = start + 1; i < n; ++i) {
            if (v[start]  * v[i] < 0) {
                v[i] += v[start];
                helper(v, start + 1, n, cnt + 1);
                v[i] -= v[start];
            }
        }
    }
};