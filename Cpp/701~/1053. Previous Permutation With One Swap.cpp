class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        int n = A.size(), i = n-1, j = n-1;
        while (i > 0 && A[i] >= A[i-1]) i--;
        if (i == 0) return A;
        while (A[j] == A[j-1] || A[j] >= A[i-1]) j--;
        swap(A[i-1], A[j]);
        return A;
    }
};