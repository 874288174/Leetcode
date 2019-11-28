class Solution {
public:
    int superPow(int a, vector<int>& b) {
        int pre = 1;
        a %= 1337;
        for (int i = b.size()-1; i >= 0; i--) {
            int cur = POW(a, b[i]);
            pre = pre*cur % 1337;
            a = POW(a, 10);
        }
        return pre;
    }
    
private:
    int POW(int x, int n) {
       int ret = 1;
       while (n--) {
           ret = ret*x % 1337;
       }    
       return ret;
    }
};