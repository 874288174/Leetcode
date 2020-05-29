// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    int read(char *buf, int n) {
        int cnt = 0;
        for (int i = 0; i <= n/4; ++i) {
            int cur = read4(cnt + buf);
            if (cur == 0) break;
            cnt += cur;
        }
        return min(cnt, n);
    }
};