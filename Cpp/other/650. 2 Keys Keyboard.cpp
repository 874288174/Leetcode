class Solution {
public:
//存在更快的log(n)算法 待补充
    int minSteps(int n) {
        if (n == 1) return 0;
        vector<int> dp(n+1, 0);
        dp[2] = 2;
        return helper(dp, n);
    }
private:
    int helper(vector<int>& dp, int k) {
        if (dp[k]) return dp[k];
        int ans = k, Sqrt = sqrt(k);
        for (int i = 2; i <= Sqrt; i++) {
            if (k%i == 0) {
                ans = min(ans, min(helper(dp, k/i)+i, helper(dp, i)+k/i));
            } 
        }
        return dp[k] = ans;
    }
};