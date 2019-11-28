class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) return INT_MAX;
        int sign = (dividend > 0) ^ (divisor > 0) ? -1 : 1;
        long long Dividend = labs(dividend);
        long long Divisor = labs(divisor);
        int res = 0;
        while (Dividend >= Divisor) {
            long long mul = 1, temp = Divisor;
            while(Dividend > (temp << 1)) {
                mul  <<= 1;
                temp <<= 1; 
            }
            res += mul;
            Dividend -= temp;
        }
        return sign*res;
    }
};