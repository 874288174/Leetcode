/*
class Solution {
public:
   string shortestPalindrome(string s) {
       int n = s.size();
       string rev(s);
       reverse(rev.begin(), rev.end()); 
       for (int i = 0; i < n; i++) {
           if (s.substr(0, n - i) == rev.substr(i))       
               return rev.substr(0, i) + s;
       }
       return "";
   }
};
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.begin(), rev.end());
        string str = s + "#" + rev;
        int n = str.size();
        vector<int> f(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (str[i] == str[len])  f[i++] = ++len;
            else if (len) len = f[len - 1];
            else  f[i++] = 0;
        }
        return rev.substr(0, s.length()- f[n - 1]) + s;
    }
}