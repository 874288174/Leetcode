class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        deque<int> deq;
        int res = 0, n = A.size();
        for (int i = 0; i < n; ++i) {
            if (!deq.empty() && i-deq.front() >= K) {
                deq.pop_front();
            }
            if (!(A[i] ^ (deq.size() % 2))) {
                if (n-i < K) return -1;
                deq.push_back(i);
                ++res;
            }
        }
        return res;
    }
};