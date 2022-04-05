class Solution {
public:
    using pii = pair<int, int>;
    vector<int> minInterval(vector<vector<int>>& v, vector<int>& queries) {
        int n = v.size(), m = queries.size();
        vector<int> res(m);
        
        sort(v.begin(), v.end());
        vector<vector<int>> qs(m);
        for (int i = 0; i < m; ++i) qs[i] = {queries[i], i};
        sort(qs.begin(), qs.end());
        multiset<int> st;
        
        int i = 0, j = 0;
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        while (j < m) {
            while (i < n && v[i][0] <= qs[j][0]) {
                pq.emplace(v[i][1], v[i][1] - v[i][0] + 1);
                st.insert(v[i][1] - v[i][0] + 1);
                ++i;
            }
            while (!pq.empty() && pq.top().first < qs[j][0]) {
                st.erase(st.find(pq.top().second));
                pq.pop();
            }
            res[qs[j++][1]] = st.empty() ? -1 : *st.begin();
        }
        return res;
    }
};