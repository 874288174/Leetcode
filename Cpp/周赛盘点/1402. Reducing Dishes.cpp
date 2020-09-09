class Solution {
public:
    int maxSatisfaction(vector<int>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int sum = 0, tmp = 0;
        for (int i = 0; i < n; ++i) {
            tmp += (i+1) * v[i];
            sum += v[i];
        }
        int res = tmp;
        for (int i = 0; i < n && v[i] < 0; ++i) {
            tmp -= sum;
            sum -= v[i];
            res = max(res, tmp);
        }
        return res;
    }
};




class Solution {
public:
    int maxSatisfaction(vector<int>& A) {
        sort(A.begin(), A.end());
        int res = 0, total = 0, n = A.size();
        for (int i = n - 1; i >= 0 && A[i] > -total; --i) {
            total += A[i];
            res += total;
        }
        return res;
    }
};