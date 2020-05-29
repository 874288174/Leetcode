class Solution {
public:
    int minCut(string s) {
        if (s.empty()) return 0;
        int n = s.size();
        vector<vector<bool>> p(n,vector<bool>(n,false));
        vector<int> f(n);
        for (int i = n-1; i >= 0; i--) {
            f[i] = n-i-1;
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i < 2 || p[i+1][j-1])) {
                    p[i][j] = true;
                    if (j == n-1) f[i]=0;
                    else f[i] = min(f[i], f[j+1]+1);
                }
            }
        }
        return f[0];
    }
};