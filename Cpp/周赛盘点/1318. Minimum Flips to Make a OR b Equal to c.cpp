//popcount c++20  == __builtin_popcount
class Solution {
public:
    int minFlips(int a, int b, int c) {
        return __builtin_popcount((a | b) ^ c) + popcount(a & b & ((a | b) ^ c));
    }
};