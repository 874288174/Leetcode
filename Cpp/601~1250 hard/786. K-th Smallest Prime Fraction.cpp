class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double left = 0, right = 1.0;
        int n = A.size();
        while (left < right) {
            double mid = (right + left) / 2;
            int cnt = 0;
            vector<int> res{0, 1};
            for(int i = 0, j = 0; i < n; i++) {
                while (j < n && A[i] >= mid*A[j]) ++j;
                cnt += n - j;
                if (j < n && res[0]*A[j] < A[i]*res[1])  res = {A[i], A[j]};
            }
            if (cnt == K)  return res;
            else if (cnt < K)   left = mid;
            else right = mid;
        }
        return {};
    }
};