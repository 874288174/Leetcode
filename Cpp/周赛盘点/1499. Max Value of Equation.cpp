class Solution {
public:
    using PII = pair<int, int>;
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        deque<PII> dq;
        int res = -2e9;
        for(const auto &pnt : points) {
            while (!dq.empty() && pnt[0] - dq.front().first > k) dq.pop_front();
            if (!dq.empty()) 
                res = max(res, dq.front().second + pnt[0] + pnt[1]);
            while (!dq.empty() && dq.back().second <= pnt[1] - pnt[0]) 
                dq.pop_back();
            dq.emplace_back(pnt[0], pnt[1] - pnt[0]);
        }
        return res;
    }
};