class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        vector<int> dp(A[0].size(), 1);
        for (auto i = 0; i < A[0].size(); ++i) {
            for (auto j = 0; j < i; ++j) {
                bool ok = true;
                for (auto k = 0; k < A.size(); ++k) {
                    if (A[k][j] > A[k][i]) {ok = false; break;}
                }
                if (ok) dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        return A[0].size() - *max_element(begin(dp), end(dp));
    }
};