class Solution {
public:
    string toHex(int num) {
        const string HEX = "0123456789abcdef";
        if (num == 0) return "0";
        string res;
        unsigned int n = num;
        while (n) {
            res = HEX[(n & 0xf)] + res;
            n >>= 4;
        }
        return res;
    }
};