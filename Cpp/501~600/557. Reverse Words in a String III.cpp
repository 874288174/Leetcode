class Solution {
public:
    string reverseWords(string s) {
        string::iterator p = s.begin(), q;
        while (p != s.end()) {
            q = p;
            while (q != s.end() && *q != ' ') q++;
            reverse(p, q);
            if (q == s.end()) break;
            p = ++q;
        }
        return s;
    }
};