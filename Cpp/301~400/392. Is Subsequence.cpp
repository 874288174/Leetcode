class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length(), j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j++ == m) return false;
            if (i == n-1) return true;
        }
        return true;
    }
};