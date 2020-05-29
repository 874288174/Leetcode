class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.size(), m = t.size(); 
        if (abs(n-m) > 1) return false;
        int len = min(s.size(), t.size());
        for (int i = 0; i < len; i++) {
            if (s[i] != t[i]) {
                if (n == m) return s.substr(i + 1) == t.substr(i + 1);
                else if (n < m) return s.substr(i) == t.substr(i + 1);
                else return s.substr(i + 1) == t.substr(i);
            }
        }
        return true;
    }
};