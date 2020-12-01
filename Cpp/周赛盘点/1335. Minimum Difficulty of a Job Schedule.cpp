class Solution {
public:
    int minDifficulty(vector<int>& jobs, int days) {
        const int n = (int)jobs.size();
        if (n < days) return -1;
        vector<int> dp(n), old(n); // new and old dp
        // fill dp for d = 1
        dp[0] = jobs[0];
        for (int i = 1; i < n; i++)
            dp[i] = max(dp[i-1], jobs[i]);
        
        // fill dp for remaining days
        for (int d = 1; d < days; d++) {
            swap(dp, old);    
            // monotonic and minimum stack {oldBest, curMax, bestSoFar}
            vector<array<int,3>> stk = {{1<<30,1<<30,1<<30}};
            for (int i = d; i < n; i++) {
                int oldBest = old[i-1];
                while (stk.back()[1] <= jobs[i]) {
                    oldBest = min(oldBest, stk.back()[0]);
                    stk.pop_back();
                }
                stk.push_back({oldBest, jobs[i], min(oldBest + jobs[i], stk.back()[2])});
                dp[i] = stk.back()[2];
            }
        }
        return dp[n-1];
    }
};









class Solution {
public:
    const int INF = 1e7;
    
    int minDifficulty(vector<int>& jobs, int days) {
        const int n = jobs.size();
        if (n < days) return -1;
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = 0; i < n; ++i) {
            int t = 0;
            for (int j = i; j < n; ++j) {
                f[i][j] = t = max(t, jobs[j]);
            }
        }

        
        vector<vector<int>> dp(2, vector<int> (n));
        int k = 0;
        for (int d = 1; d <= days; ++d) {
            auto &cur = dp[k], &pre = dp[k^1];
            for (int i = 0; i < n; ++i) {
                cur[i] = INF;
                if (d == 1) cur[i] = f[0][i];  
                else for (int j = 0; j < i; ++j) {
                    cur[i] = min(cur[i], pre[j] + f[j+1][i]);
                }
            }
            k ^= 1;
        }
        return dp[k^1].back();
    }
};