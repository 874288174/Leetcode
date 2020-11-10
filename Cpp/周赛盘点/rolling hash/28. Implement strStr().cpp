class Solution {
public:
    int strStr(string haystack, string needle) {
        using ul = unsigned long;
        ul q = 1e9 + 7;
        int m = needle.length();
        int n = haystack.length();
        if (m == 0 || n == 0 || m > n) 
            return m == 0 ? 0 : -1;

        ul d = 31;
        ul t = haystack[0];
        ul p = needle[0];
        ul h = 1;

        for(int i = 1; i < m; i++) {
            h = (h*d)%q;
            p = (p*d + needle[i])%q;
            t = (t*d + haystack[i])%q;
        }

        for(int i = 0; i <= n-m; i++) {
            if(p == t) {
                int j = 0;
                for(; j < m && needle[j] == haystack[i+j]; j++);
                if(j == m) 
                    return i;
            }

            if(i < n-m)
                t = ((t-haystack[i]*h)*d + haystack[i+m])%q;
        }

        return -1;
    }
};