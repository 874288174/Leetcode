class Solution {
public:
    using pii = pair<int, int>;
    int eatenApples(vector<int>& apples, vector<int>& days) {
        int n = apples.size(), res = 0;
        auto cmp = [](const pii& lhs, const pii& rhs) {
            return lhs.first > rhs.first;
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        int i = 0;
        while (i < n || !pq.empty()) {
            if (i < n && apples[i]) pq.push({days[i]+i, apples[i]});
            while (!pq.empty() && pq.top().first <= i) pq.pop();
            if (!pq.empty()) {
                auto t = pq.top();
                pq.pop();
                if (--t.second != 0) pq.push(t);
                res++;
            }
            ++i;
        }
        return res;
    }
};