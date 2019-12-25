class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        while (n-- >= 1) {
            int t = 9;
            for (int i = 9; i >= 10-n; --i) {
                t *= i;
            }
            res += t;
        }
        return res;
    }
};