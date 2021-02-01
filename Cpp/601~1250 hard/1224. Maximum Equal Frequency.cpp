class Solution {
public:
    int maxEqualFreq(vector<int>& v) {
        unordered_map<int, int> m, cnt;
        int n = v.size(), res = 0;
        if (n <= 2) return n;
        for (int i = 0; i < n; ++i) {
            if (m.count(v[i]) && --cnt[m[v[i]]] == 0) cnt.erase(m[v[i]]);
            m[v[i]]++;
            cnt[m[v[i]]]++;
            if (cnt.size() == 1 && (cnt.begin()->first == 1 || cnt.begin()->second == 1)) res = i+1;
            else if (cnt.size() == 2) {
                auto p = cnt.begin(), q = next(p);
                if ((p->second == 1 && p->first == q->first +1) || (q->second == 1&& p->first == q->first -1)) res = i+1;
                else if ((p->second == 1 && p->first == 1) || (q->second == 1&& q->first == 1)) res = i+1;
                
            }
        }
        return res;
    }
};