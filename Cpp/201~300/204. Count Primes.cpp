class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool> v(n, false);
        int Sqrt = sqrt(n)+0.5, cnt = n/2;
        for (int i = 3; i <= Sqrt; i += 2) {
            for (int j = i*i; j < n; j += 2*i) {
                if (!v[j]) {
                    v[j] = true;
                    --cnt;
                }
            }
        }
        return cnt;
    }
};