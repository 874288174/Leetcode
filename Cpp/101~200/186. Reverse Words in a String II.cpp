class Solution {
public:
    void reverseWords(vector<char>& str) {
        vector<char>::iterator p = str.begin(), q = p;
        while (p != str.end()) {
            while (q != str.end() && *q != ' ') q++;
            reverse(p, q);
            if (q == str.end()) break;
            p = ++q;
        }
        reverse(str.begin(), str.end());
    }
};