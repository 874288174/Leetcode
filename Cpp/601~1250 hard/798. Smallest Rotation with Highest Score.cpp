class Solution {
public:
    int bestRotation(vector<int>& A) {
        int N = A.size(), res = 0;
        vector<int> mark(N, 0);
        for (int i = 0; i < N; ++i) {
            if (A[i] >= N) continue;
            int k_in = (i + 1) % N;
            int k_out = (i + 1 + N - A[i]) % N;
            if (i > A[i]) {
                ++mark[0];      --mark[k_out];
                ++mark[k_in];   //--mark[N];
            }
            else {
                ++mark[k_in];
                --mark[k_out];
            }
        }
        int score = 0, max_score = -1;
        for (int i = 0; i < N; ++i) {
            score += mark[i];
            if (score > max_score) {
                res = i;
                max_score = score;
            }
        }
        return res;
    }
};