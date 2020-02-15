class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int f = 0, g = 1;
        for (int i = 1; i < n; ++i) {
            int new_f = INT_MAX, new_g = INT_MAX;
            if (A[i] > A[i-1] && B[i] > B[i-1]) {
                new_f = f;
                new_g = g+1;
            }
            if (A[i] > B[i-1] && B[i] > A[i-1]) {
                new_f = min(new_f, g);
                new_g = min(new_g, f+1);
            }
            f = new_f;
            g = new_g;
        }
        return min(f, g);
    }
};