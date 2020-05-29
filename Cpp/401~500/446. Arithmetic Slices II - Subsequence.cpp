class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int n = A.size();
        vector<unordered_map<long long, int>> dp(n);
        int res = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                auto delta = (long long)A[i] - (long long)A[j];
                int tmp = dp[j].count(delta) ? dp[j][delta] : 0;
                res += tmp;
                dp[i][delta] += 1+tmp;
            }
        }
        return res;
    }
};