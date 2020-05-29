class Solution {
public:
    const int MOD = 1337;
    int superPow(int a, vector<int>& b) {
        int pre = 1;
        a %= MOD;
        for (int i = b.size()-1; i >= 0; i--) {
            int cur = POW(a, b[i]);
            pre = pre*cur % MOD;
            a = POW(a, 10);
        }
        return pre;
    }
    
private:
    int POW(int x, int n) {
       int ret = 1;
       while (n--) {
           ret = ret*x % MOD;
       }    
       return ret;
    }
};
