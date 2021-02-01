class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        int n = A.size();
        // dp[mask][i] : min superstring made by strings in mask,
        // and the last one is A[i]
        vector<vector<string>> dp(1<<n, vector<string>(n));
        vector<vector<int>> overlap(n, vector<int>(n,0));
        
        // calculate overlap for A[i], A[j]
        for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) if (i != j) {
            for (int k = min(A[i].size(), A[j].size()); k > 0; --k) {
                if (A[i].substr(A[i].size()-k) == A[j].substr(0,k)) {
                    overlap[i][j] = k;
                    break;
                }
            }
        }
    
        for(int i = 0; i < n; ++i) dp[1<<i][i] += A[i];
     
        for (int mask = 1; mask<(1<<n); ++mask) {
            for (int j = 0; j < n; ++j) { 
                if (!(mask & (1<<j))) continue;
                for (int i = 0; i < n; ++i) {
                    if (i == j || !(mask&(1<<i))) continue;
                    string s = dp[mask^(1<<j)][i]+A[j].substr(overlap[i][j]);
                    if (dp[mask][j].empty() || s.size() < dp[mask][j].size())
                        dp[mask][j] = std::move(s);
                }
            }
        }

        string res = dp.back()[0];
        for (const auto &s : dp.back()) {
            if (s.size() < res.size()) {
                res = s;
            }
        }
        return res;
    }
};