class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long long n = A.size(), sum = 0, res = 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            res += i * A[i];
        }
        long long temp = res;
        for (int i = 0; i < n; ++i) {
            temp += n*A[i] - sum;
            res = max(temp, res);
        }
        return res;
    }
};