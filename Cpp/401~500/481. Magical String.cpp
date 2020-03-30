class Solution {
public:
    int magicalString(int n) {
        if (n == 1) return 1;
        int i = 0;
        string s = "1";
        char cur = '2';
        while (s.length() < n) {
            s += string(s[i++]-'0', cur);
            cur = (cur == '1' ? '2' : '1');
        }
        int res = 0;
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == '1') ++res;
        }
        return res;
    }
};