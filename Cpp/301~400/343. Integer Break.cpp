class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n-1;
        vector<int> res(n+1, 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                res[i] = max(res[i], j*res[i-j]);
            }
        }
        return res[n];
    }
};