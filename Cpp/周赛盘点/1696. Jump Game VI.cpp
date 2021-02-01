class Solution {
public:
    using pii = pair<int, int>;
    
    int maxResult(vector<int>& nums, int k) {
        deque<pii> deq{{0, nums[0]}};
        int n = nums.size();
        for (int i = 1; i < n; ++i) {
            int t = nums[i] + deq.front().second;
            while (!deq.empty() && t > deq.back().second) {
                deq.pop_back();
            }
            while (!deq.empty() && i - deq.front().first >= k) deq.pop_front();
            deq.emplace_back(i, t);
        }
        return deq.back().second;
    }
};