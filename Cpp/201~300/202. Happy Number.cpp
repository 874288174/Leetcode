class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> My_set;
        while (1) {
            int t = 0;
            while (n) {
                t += (n%10)*(n%10);
                n /= 10;
            }
            if (t == 1) return true;
            else if (My_set.count(t)) return false;
            My_set.insert(n = t);
        }
        return true;
    }
};