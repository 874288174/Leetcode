class Solution {
public:
    string getPermutation(int n, int k) {
    string s(n, '0');
    for (int i = 0; i < n; ++i) s[i] += i + 1;
    return kth_permutation(s, k);
}
    
private:
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i < n+1; ++i)  result *= i;
        return result;
    }

    string kth_permutation(string &s, int k) {
        int n = s.size();
        string res;
        int base = factorial(n - 1);
        --k; // ¿µÍÐ±àÂë´Ó0¿ªÊ¼
        for (int i = n - 1;; i--) {
            auto a = next(s.begin(), k / base);
            res.push_back(*a);
            s.erase(a);
            if(!i) break;
            k %= base;
            base /= i;
        }
        return res;
    }
};