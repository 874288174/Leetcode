class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while (a || b || c) {
            int aa = (a & 1);
            int bb = (b & 1);
            int cc = (c & 1);
            //cout << aa << ' ' << bb << ' ' << cc << "\n";
            if ((aa | bb) == 1) {
                if (cc != 1) {
                    if (aa == 1 && bb == 1) res += 2;
                    else res += 1;
                }
            }
            else {
                if (cc == 1) res++;
            }
            a >>= 1;
            b >>= 1;
            c >>= 1;
            //cout << a << " " << b << " " << c << std::endl;
        }
        return res;
    }
};


//popcount c++20  == __builtin_popcount
class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a | b) ^ c) + popcount(a & b & ((a | b) ^ c));
    }
};