class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        vector<int> f(n, 0);
        for(int i = 1, len = 0; i < n;) {
            if (s[i] == s[len]) f[i++] = ++len;
            else if (len) len = f[len-1]; 
            else f[i++] = 0;
        }
        return f[n-1] && n % (n-f[n-1]) == 0;
    }
};

/*
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i <= n/2; i++) {
            if (n % i != 0) continue;
            int cnt = n / i;
            string a, b = s.substr(0, i); 
            while (cnt--) a += b;
            if (a == s) return true;
        }
        return false;
    }
};
*/