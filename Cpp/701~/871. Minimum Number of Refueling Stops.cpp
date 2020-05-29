class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //it can run dp[k] at most , which stops k times
        int n = stations.size();
        vector<long long> dp(n+1, 0);
        dp[0] = startFuel;
        for (int i = 0; i < n; ++i) {
            for (int t = i; t >= 0; --t) {
                if (dp[t] >= stations[i][0]) {
                    dp[t+1] = max(dp[t+1], dp[t] + static_cast<long long> (stations[i][1]));
                }
            }
        }
        for (int i = 0; i <= n; ++i)
            if (dp[i] >= target) return i;
        return -1;
    }
};