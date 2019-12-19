class Solution {
public:
    struct node{
        int x, y, val;
        bool operator < (const node& rhs) const {
            return val > rhs.val;
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return {};
        int n = nums1.size(), m = nums2.size();
        priority_queue<node> pq;
        pq.push({0, 0, nums1[0] + nums2[0]});
        vector<vector<int>> res;
        while (!pq.empty() && res.size() < k) {
            auto t = pq.top();
            res.push_back({nums1[t.x], nums2[t.y]});
            pq.pop();
            if (t.x+1 < n) pq.push({t.x+1, t.y, nums1[t.x+1] + nums2[t.y]});
            if (t.x == 0 && t.y+1 < m) pq.push({t.x, t.y+1, nums1[t.x] + nums2[t.y+1]});
        }
        return res;
    }
};