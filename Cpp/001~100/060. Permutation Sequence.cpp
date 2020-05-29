class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n, '0');
        for (int i = 0; i < n; ++i) s[i] += i + 1;
        // 康托编码从0开始
        return kth_permutation(s, n, k-1);
    }
    
private:
    int factorial(int n) {
        int res = 1;
        while (n)  res *= n--;
        return res;
    }

    string kth_permutation(string &s, int n, int k) {
        string res;
        int base = factorial(n);
        for (int i = n; i > 0; i--) {
            base /= i;
            auto a = next(s.begin(), k / base);
            res.push_back(*a);
            s.erase(a);
            k %= base;
        }
        return res;
    }
};
