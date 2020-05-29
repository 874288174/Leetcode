class Solution {
public:
    bool isUgly(int num) {
        if(num < 1) return false;
        int a[3] = {2, 3, 5};
        for(auto &i : a) {
            while (num % i == 0) num /= i;
        }
        return num == 1;
    }
};