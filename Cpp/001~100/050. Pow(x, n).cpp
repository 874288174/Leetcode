class Solution {
public:
    double myPow(double x, int n) {
        if(x == 1 || n == 0) return 1;
        if (n < 0)  x = 1/x;
        double res = 1;
        unsigned long long m = abs(n);
        while (m) {
            if (m&1) res *= x;
            x *= x;
            m >>= 1;
        }
        return res ;
    }
}