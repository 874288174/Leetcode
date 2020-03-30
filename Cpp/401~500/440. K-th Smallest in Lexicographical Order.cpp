class Solution {
public:
    int findKthNumber(int n, int k) {
        long cur = 1, i = 1;
        while (i != k) {
            long cnt = getCount(cur, n);
            if (i + cnt <= k) {
                i += cnt;
                ++cur;
            }
            else {
                i += 1;
                cur = cur * 10;
            }
        }
        return static_cast<int> (cur);
    }
    
private:
    //返回以cur为前缀的个数
    long getCount(long cur, long n) {
        long cnt = 0, next = cur + 1;
        while (cur <= n) {
            cnt += min(n + 1, next) - cur;
            cur *= 10;
            next *= 10;
        }
        return cnt;
    }
};