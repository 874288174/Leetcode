class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size(); 
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while (i < slen) {
            if (j < plen && p[j] == '*') { 
                //meet a new '*', update traceback i/j info
                iStar = i;
                jStar = j++;
            }
            else if (j < plen && (p[j] == s[i] || p[j] == '?')) {  
                ++i, ++j;
            }
            else {
               // mismatch happens
               if (iStar < 0) return false;
               // met a '*' before, then do traceback
               i = iStar++;
               j = jStar + 1;
            }
        }
        while (j < plen && p[j] == '*') ++j;
        return j == plen;
    }
};
