class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0;
        while (1) {
            int k = c - i*i;
            if (k < 0) return false; 
            int j = sqrt(k);
            if (j*j == k) return true;
            if (j < i++) return false;
        }
        return true;
    }
};