class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0) return 0;
        int f_0 = 0, f_1 = k;
       // f_0 = 前两次相同颜色*(k-1) + 一次颜色相同*(k-1);  
       // f_1 = 一次颜色相同
        for (int i = 1; i < n; i++) {
            int temp = (f_0 + f_1) * (k-1); 
            f_0 = f_1;
            f_1 = temp;
        }
        return f_0 + f_1;
    }
};