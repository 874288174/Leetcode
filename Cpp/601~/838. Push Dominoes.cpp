class Solution {
public:
    string pushDominoes(string s) {
        s = 'L' + s + 'R';
        int n = s.length();
        string res = "";
        for (int i = 0, j = 1; j < n; ++j) {
            if (s[j] == '.') continue;
            int len = j - i - 1;
            if (i > 0) res += s[i];
            if (s[i] == s[j]) res += string(len, s[i]);
            else if (s[i] == 'L' && s[j] == 'R') res += string(len, '.');
            else res += string(len / 2, 'R') 
                        + string(len % 2,'.') + string(len / 2, 'L');
            i = j;
        }
        return res;
    }
};