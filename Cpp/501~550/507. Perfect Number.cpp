class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 0, Sqrt = sqrt(num);
        for (int i = 1; i <= Sqrt; i++) {
            if (num % i == 0) {
                if (i == 1 || num/i == i) sum += i;
                else sum += i + num/i;
                if (sum > num) break;
            }
        }
        return sum == num;
    }
};