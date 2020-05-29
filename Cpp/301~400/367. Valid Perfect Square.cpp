/*
class Solution {
public:
    bool isPerfectSquare(int num) {
       long r = num;
       while (r*r > num)
          r = (r + num/r) / 2;
       return r*r == num;
    }
};
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        long long l = 0, r = num;
        while (l <= r) {
            auto mid = l + (r-l)/2;
            auto sqmid = mid * mid;
            if (sqmid == num) return true;
            else if (sqmid < num) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};