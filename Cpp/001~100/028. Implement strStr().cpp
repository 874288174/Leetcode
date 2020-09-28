class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if (!n)  return 0;
        vector<int> f = get_fail(needle);
        for (int i = 0, j = 0; i < m;) {
            if (haystack[i] == needle[j]) { 
                i++;
                if (++j == n)  return i-j;
            }
            else if (j) j = f[j - 1];
            else i++;
        }
        return -1;
    }
private:
    vector<int> get_fail(string str) {
        int n = str.size();
        vector<int> f(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (str[i] == str[len])  f[i++] = ++len;
            else if (len) len = f[len - 1];
            else  f[i++] = 0;
        }
        return f;
    }
};