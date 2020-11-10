class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        vector<int> dp(A);
        int res = A[0];
        deque<int> deq;
        for (int i = 0; i < A.size(); ++i) {
            if (!deq.empty()) dp[i] = max(dp[i], dp[deq.front()] + A[i]);
            res = max(res, dp[i]);
            while (!deq.empty() && dp[deq.back()] < dp[i])
                deq.pop_back();
            deq.push_back(i);
            if ((i+1) - deq.front() > k) deq.pop_front();
        }
        return res;
    }
};







class Solution {
public:
    int constrainedSubsetSum(vector<int>& A, int k) {
        deque<int> deq;
        int res = A[0];
        for (int i = 0; i < A.size(); ++i) {
            A[i] += deq.size() ? deq.front() : 0;
            res = max(res, A[i]);
            while (!deq.empty() && A[i] > deq.back())
                deq.pop_back();
            if (A[i] > 0) deq.push_back(A[i]);
            if (i >= k && !deq.empty() && deq.front() == A[i - k])
                deq.pop_front();
        }
        return res;
    }
};