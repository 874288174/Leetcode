class Solution {
public:
//(2^n - 1) % 3 = Σ(iCn * 3^n * (-1)^(n-i)) % 3 =  ((-1)^n - 1) % 3
    bool isPowerOfFour(int num) {
        return num > 0 && (num & (num - 1)) == 0 && (num - 1) % 3 == 0;
        //return (num > 0) && ((num & (num - 1)) == 0) && ((num & 0x55555555) == num);
    }
};