class Solution {
public:
using pii = pair<int, int>;

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;        
        if (nums1.empty() || nums2.empty()) return res;
        int n = nums1.size(), m = nums2.size();
        auto cmp = [&nums1, &nums2](const auto& lhs, const auto &rhs) {
            return nums1[lhs.first] + nums2[lhs.second] > nums1[rhs.first] + nums2[rhs.second];
        };
        priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < m; ++i) pq.emplace(0, i);

        while (!pq.empty() && res.size() < k) {
            auto [x, y] = pq.top();
            res.push_back({nums1[x], nums2[y]});
            pq.pop();
            if (x+1 < n) pq.emplace(x+1, y);
        }
        return res;
    }
};
