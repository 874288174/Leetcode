class Solution {
public:
    int countDigitOne(int n) {
        int res = 0;
        if (n <= 0) return res;
        long int high = n, low = 0, fact = 1, cur;
        while (high) {
            cur = high%10;
            high /= 10; 
            res += (high+ (cur > 1 ? 1: 0))*fact+(cur == 1 ? low+1 : 0);
            low += fact*cur;
            fact *= 10;
        }
        return res;
    }
};