class Solution {
public:
    int f(int x) {return x == 1 ? 1 : x*f(x-1);}
    
    int numSquarefulPerms(vector<int>& A) {
        int n = A.size(), m = 1 << n, res = 0;
        vector<vector<int>> dp(n, vector<int> (m, 0));
        for (int i = 0; i < n; ++i) dp[i][1<<i] = 1;
            
        vector<vector<int>> g(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int Sqrt = sqrt(A[i] + A[j]);
                if (Sqrt*Sqrt == A[i] + A[j]) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

    
         for (int s = 0; s < m; ++s) {
            for (int i = 0; i < n; ++i) if (s&(1<<i)) {
                for (int j : g[i]) if (s&(1<<j)) {
                    dp[i][s] += dp[j][s^(1<<i)];
                }
            }
        }
        for (int i = 0; i < n; ++i) res += dp[i].back();
        map<int, int> mp;
        for (auto i : A) ++mp[i];
        for (auto i : mp) res /= f(i.second);
        
        return res;
    }
};