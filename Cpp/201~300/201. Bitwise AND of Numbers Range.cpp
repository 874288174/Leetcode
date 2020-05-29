class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int x = 0x40000000, res = 0;
        while (x) {
            if((m & x) == (n & x)) res += (m & x);
            else break;
            x >>= 1;
        }
        return res;
    }
};