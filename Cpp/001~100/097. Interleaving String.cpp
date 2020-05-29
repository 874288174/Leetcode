class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), l = s3.length();
        if (n+m != l) return false;
        else if (n < m) return isInterleave(s2, s1, s3);
        vector<vector<bool>> f(n+1, vector<bool>(m+1, false));
        f[0][0] = true;
        for (int k = 1; k <= l; k++) {
            for (int j = max(0, k-n); j <= min(m, k); j++) {
                int i = k-j;
                f[i][j] = (i >= 1 && s1[i-1] == s3[i+j-1] && f[i-1][j])
                       || (j >= 1 && s2[j-1] == s3[i+j-1] && f[i][j-1]);
            }
        }
        return f[n][m];
    } 
};
