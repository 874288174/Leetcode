class Solution {
public:
    string reverseStr(string s, int k) {
        auto l = s.begin();
        while (l != s.end()) {
            auto r = (s.end() - l > k) ? l + k : s.end();
            reverse(l, r);
            l = (s.end() - r > k) ? r + k : s.end();
        }
        return s;
    }
};