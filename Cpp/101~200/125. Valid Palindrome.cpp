class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) return true;
        auto p = &s[0], q =  &s[s.length()-1];
        while (p < q) {
            while (p < q && !isalnum(*p)) p++;
            while (p < q && !isalnum(*q)) q--;
            if (tolower(*p) != tolower(*q)) return false;
            p++; q--;
        }
        return true;
    }
};