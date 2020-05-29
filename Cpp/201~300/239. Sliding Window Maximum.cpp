class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0;
        vector<int> res;
        deque<int> deq;
        for (int i = 0; i < n; i++) {
            while(!deq.empty() && nums[deq.back()] <= nums[i]) {
                deq.pop_back();
            } 
            deq.push_back(i);
            if(i-deq.front() >= k) deq.pop_front();
            if(i >= k-1) res.push_back(nums[deq.front()]); 
        }
        return res;
    }
};