class Solution {
public:
    int numTilings(int N) {
       //0  f0    1  f1     0  f2    1  f3
       //0        0         1        1
       long long f0 = 1, f1 = 0, f2 = 0, f3 = 1;
       const long long MOD = 1e9 + 7;
       while (--N) {
           long long new_f0 = f3;
           long long new_f1 = f0 + f2;
           long long new_f2 = f0 + f1;
           long long new_f3 = f0 + f1 + f2 + f3;
           f0 = new_f0 % MOD;
           f1 = new_f1 % MOD;
           f2 = new_f2 % MOD;
           f3 = new_f3 % MOD;
           //cout << f0 << "  " << f1 << " " << f2 << " " << f3 << "\n";
       }
       return f3;
    }
};