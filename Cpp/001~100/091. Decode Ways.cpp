
class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (!n || s[0] == '0') return 0;
        else if(n == 1) return 1;
        int f_0 = 1;
        int f_1 = (s[1] == '0' ? 0 : f_0) 
                 + (is_ok(s.substr(0, 2)) ? 1 : 0);
        for (int i = 2; i < n; i++) {
            int f_2 = (s[i] == '0' ? 0 : f_1) 
                     + (is_ok(s.substr(i-1, 2)) ? f_0 : 0);
            f_0 = f_1;
            f_1 = f_2;
        }
        return f_1;
    }
private:
    bool is_ok(string s) {
        return s[0] == '1' || (s[0] == '2' && s[1] <= '6');
    }
};
