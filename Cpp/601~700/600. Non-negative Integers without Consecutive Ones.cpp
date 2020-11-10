class Solution {
public:
    int findIntegers(int num) {
        //0000~11111  = 00000~01111 + 10000~10111
        int f[32];
        f[0] = 1, f[1] = 2;
        for (int i = 2; i < 32; ++i) f[i] = f[i-1] + f[i-2];
        int res = 0, k = 30;
        while (k >= 0) {
            if (num&(1<<k)) {
                res += f[k];
                if (num & 1<<k+1) return res;
            }
            --k;
        }
        return res+1;
    }
};