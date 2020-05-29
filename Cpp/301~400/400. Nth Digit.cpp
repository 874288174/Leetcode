class Solution {
public:
    int findNthDigit(int n) { 
        int k = 1;   
        // k位数第n个
        while (n > 9*pow(10, k-1)*k) {
            n -= 9*pow(10, k-1)*k;
            k++;
        }
        int m = (n-1)/k, num = pow(10, k-1)+m; 
        n -= m*k;
        // num的第n位, 即从右往左数第k+1-n位
        return (num / (int)pow(10, k-n)) % 10;
    }
};