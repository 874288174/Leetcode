class Solution {
public:
    string addBinary(string a, string b) {
       int c = 0;
       string res;
       reverse(a.begin(), a.end());
       reverse(b.begin(), b.end()); 
       auto p = a.begin(), q = b.begin();
       while (p != a.end() || q != b.end()) {
           if (p != a.end()) {
               c += *p-'0';
               p++;
           }
           if (q != b.end()) {
               c += *q-'0';
               q++;
           }
           res += c%2+'0';
           c /= 2;
       }
       if(c) res += '1';
       reverse(res.begin(), res.end());
       return res;
    }
};