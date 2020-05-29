class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int len0 = low.length(), len1 = high.length();
        int res = 0;
        for (int n = len0; n <= len1; n++) {
            vector<string> v = f(n, n);
            if (n != len0 && n != len1) res += v.size();
            else for (auto &num : v) {
                if (len0 == len1) {
                    if (num >= low && num <= high) res++;
                }
                else if (n == len0 && num >= low) res++;
                else if (n == len1 && num <= high) res++;
            }
        }
        return res;
    }
    
private:
    vector<string> f(int m, int n) {
        if (m == 0) return {""};
        if (m == 1) return {"0", "1", "8"};
        vector<string> v(f(m-2, n)), res;
        for (auto &a : v) {
            if (m != n) res.push_back("0" + a + "0");
            res.push_back("1" + a + "1");
            res.push_back("6" + a + "9");
            res.push_back("8" + a + "8");
            res.push_back("9" + a + "6");
        }
        return res;
    }
};