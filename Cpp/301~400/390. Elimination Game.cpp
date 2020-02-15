class Solution {
public:
    int lastRemaining(int n) {
        int A = 1, B = 0;
        int flag = 0;
        while (n != 1) {
            if (n % 2 == 0 && flag) B -= A;
            A *= 2;
            n /= 2;
            flag ^= 1;
        }
        return A + B;
    }
};