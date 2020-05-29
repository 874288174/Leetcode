class Solution {
public:
    bool isPowerOfTwo(int n) {
        int cnt = 0;
        while (n) {
            if (n & 0x00000001) ++cnt;
            if (cnt >= 2) return false;
            n >>= 1;
        }
        return cnt == 1;
    }
};






//////////////////////
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        else return (n & (n-1)) == 0;
    }
};