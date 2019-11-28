class Solution {
public:
    bool canPermutePalindrome(string s) {
        bitset<256> b;
        for (auto &c : s) {
            b.flip(c);
        }
        return b.count() < 2;
    }
};
/*
class Solution {
public:
    bool canPermutePalindrome(string s) {
        int n = s.length();
        vector<bool> v(256, false);
        for (auto &c : s) {
           if (v[c]) n -= 2;
           v[c] = !v[c];
        }
        return n <= 1;
    }
};
*/