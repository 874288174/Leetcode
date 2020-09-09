class Solution {
public:
    string getHappyString(int n, int k) {
        auto prem = 1 << (n - 1);
        if (k > 3 * prem)
            return "";
        string s = string(1, 'a' + (k - 1) / prem);
        while (prem > 1) {
            k = (k - 1) % prem + 1;
            prem >>= 1;
            s += (k - 1) / prem == 0 ? 'a' + (s.back() == 'a') : 'b' + (s.back() != 'c');
        }
        return s;
    }
};




class Solution {
public:
    string getHappyString(int n, int k) {
        if (k > 3*(1 << (n-1))) return "";
        --k;
        string s;
        while (1) {
            int t = k / (1 << (n-1));
            k -= t * (1 << (n-1));
            char c;
            if (s == "") c = 'a' + t;
            else if (s.back() == 'a') {
                if (t == 0) c = 'b';
                else c = 'c';
            }
            else if (s.back() == 'b') {
                if (t == 0) c = 'a';
                else c = 'c';
            }
            else if (s.back() == 'c') {
                if (t == 0) c = 'a';
                else c = 'b';
            }
            s += c;
            if (--n == 0) break;
        }
        return s;
    }
};