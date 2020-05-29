class Solution {
public:
    void reverseWords(string &s) {
        while (!s.empty() && s[0] == ' ') s.erase(0, 1);
        while (!s.empty() && s.back() == ' ') s.erase(s.size()-1);  
        if (s.empty()) return;  
        auto p = s.begin(), q = p;
        while (1) {
            while (q != s.end() && *q != ' ') q++;
            reverse(p, q);
            if (q == s.end()) break;
            p = ++q;
            while (p != s.end() && *p == ' ') p = s.erase(p);
        }
        reverse(s.begin(), s.end());
    }
};