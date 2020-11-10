class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        vector<int> pre(n);
        for(const auto &e : dependencies){
            pre[e[1]-1] |= 1 << (e[0]-1);
        }
        vector<int> dp(1 << n, n); 
        dp[0] = 0;
        for (int i = 0; i < (1 << n); ++i){
            int ex = 0;
            for (int j = 0; j < n; ++j) { 
                if ((i & pre[j]) == pre[j]) 
                    ex |= 1 << j;
            }
            ex &= ~i;
            for (int s = ex; s; s = (s - 1) & ex) {
                if (__builtin_popcount(s) <= k) {
                    dp[i | s] = min(dp[i | s], dp[i] + 1);
                }
            }
        }
        return dp.back();
    }
};