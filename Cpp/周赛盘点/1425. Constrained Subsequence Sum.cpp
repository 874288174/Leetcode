class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n);
        int res = INT_MIN;
        deque<int> deq;
        for (int i = 0; i < n; ++i) {
            dp[i] = nums[i]; 
            if (!deq.empty()) dp[i] = max(dp[i], dp[deq.front()] + nums[i]);
            while (!deq.empty() && dp[deq.back()] < dp[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
            if ((i+1) - deq.front() > k) deq.pop_front();
           
            res = max(res, dp[i]);
        }
        return res;
    }
};







class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        deque<int> q;
        int res = A[0];
        for (int i = 0; i < A.size(); ++i) {
            A[i] += q.size() ? q.front() : 0;
            res = max(res, A[i]);
            while (q.size() && A[i] > q.back())
                q.pop_back();
            if (A[i] > 0)
                q.push_back(A[i]);
            if (i >= k && q.size() && q.front() == A[i - k])
                q.pop_front();
        }
        return res;
    }
};