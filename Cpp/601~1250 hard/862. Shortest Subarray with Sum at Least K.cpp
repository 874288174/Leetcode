//O(nlogn)
class Solution {
public:
    using pii = pair<int, int>;
    int shortestSubarray(vector<int>& A, int K) {
        priority_queue<pii, vector<pii>, greater<>> pq;
        int N = A.size(), sum = 0, res = N+1;
        for (int i = 0; i < N; i++) {
            sum += A[i];
            if (sum >= K) res = min(res, i+1);
            
            while (!pq.empty() && sum - pq.top().first >= K) {
                res = min(res, i - pq.top().second);
                pq.pop();
            }
            pq.emplace(sum, i);
        }
        return res <= N ? res : -1;
    }
};



//O(n)
class Solution {
public:
    int shortestSubarray(vector<int> A, int K) {
        int N = A.size(), res = N + 1;
        deque<int> deq;
        for (int i = 0; i < N; i++) {
            if (i > 0) A[i] += A[i - 1];
            if (A[i] >= K) res = min(res, i + 1);
            while (!deq.empty() && A[i] <= A[deq.back()])
                deq.pop_back();
            while (!deq.empty() && A[i] - A[deq.front()] >= K) {
                res = min(res, i - deq.front());
                deq.pop_front();
            }
            deq.push_back(i);
        }
        return res <= N ? res : -1;
    }
};