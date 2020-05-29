class Solution {
public:
    bool canWin(string s) {
        for (int i = s.length()-1; i > 0; i--) {
            if (s[i] == '+' && s[i-1] == '+') {
                string t = s.substr(0, i-1) + "--" + s.substr(i+1);
                if (!canWin(t)) return true;
            }
        }
        return false;
    }
};