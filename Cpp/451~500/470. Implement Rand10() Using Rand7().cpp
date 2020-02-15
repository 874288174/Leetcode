// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        while (1) {
            int num = 7 * (rand7() - 1) + (rand7() - 1);
            int ret = 1 + num/4;
            if (ret < 11) return ret;
        }
    }
};