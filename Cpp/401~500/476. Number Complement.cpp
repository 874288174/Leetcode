class Solution {
public:
    int findComplement(int num) {
        for(unsigned i = 1; i <= num; i <<= 1) num ^= i; 
        return num;
    }
};
/*
class Solution {
public:
    int findComplement(int num) {
        int cnt = 0, n = num;
        while (n) {
            n >>= 1;
            cnt++;
        }
        return  (static_cast<long long> (1) << cnt) - num - 1;
    }
};
*/
