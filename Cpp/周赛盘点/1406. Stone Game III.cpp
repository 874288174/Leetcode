//dp[i]表示Alice和Bob的差值
class Solution {
public:
    string stoneGameIII(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n+1, -1e9);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i) {
            int S = 0;
            for (int k = 0, j = i; k < 3 && j < n; ++k, ++j) {
                S += A[j];
                dp[i] = max(dp[i], S - dp[j + 1]);
            }
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};





class Solution {
public:
    string stoneGameIII(vector<int>& A) {
        vector<int> dp(4);
        for (int i = A.size() - 1; i >= 0; --i) {
            dp[i % 4] = -1e9;
            for (int k = 0, take = 0; k < 3 && i + k < A.size(); ++k)
                dp[i % 4] = max(dp[i % 4], (take += A[i + k]) - dp[(i + k + 1) % 4]);
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};