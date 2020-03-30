class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res;
        bool isNeg = num < 0;
        while (num != 0) {
            res += char('0'+abs(num % 7));
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return isNeg ? '-' + res : res;
    }
};