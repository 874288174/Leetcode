//dp(n, k) = (dp(n-1, k) + k) % n 

class Solution {
public:
    int findTheWinner(int n, int m) {
        int res = 0;
        for(int i = 2; i <= n; ++i)  {  
            res = (res + m) % i;  
        }  
        return res + 1;
    }
};