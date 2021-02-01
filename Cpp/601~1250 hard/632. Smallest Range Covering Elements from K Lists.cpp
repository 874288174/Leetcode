class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        using vi = vector<int>::iterator;
        using pvv = pair<vi, vi>;
        
        
        auto cmp = [](const pvv &p1, const pvv &p2) {
            return *p1.first > *p2.first;
        };
        
        int lo = INT_MAX, hi = INT_MIN;
        priority_queue<pvv, vector<pvv>, decltype(cmp)> pq(cmp);
        for (auto &row : nums) {
            lo = min(lo, row[0]);
            hi = max(hi, row[0]);
            pq.emplace(row.begin(), row.end());
        }
        
        vector<int> res{lo, hi};
        while (1) {
            auto p = pq.top();
            pq.pop();
            ++p.first;
            if (p.first == p.second) break;
            pq.push(p);
            
            lo = *pq.top().first;
            hi = max(hi, *p.first);
            if (hi - lo < res[1] - res[0])
                res = {lo, hi};
        }
        return res;
    }
};