class Solution {
public:
    int maxValueAfterReverse(vector<int>& A) {
        int n = A.size();
        //a [b...c] d => a [c...b] d
        int t0 = -1e9, t1 = -1e9, t2 = -1e9, t3 = -1e9, diff = 0, res = 0;
        
        for (int i = 1; i < n; i++) {
            diff = max(diff, -abs(A[i]-A[i-1]) + abs(A[n-1]-A[i-1]));
        }

        for (int i = n-2; i >= 0; i--) {
            diff = max(diff, -abs(A[i]-A[i+1]) + abs(A[0]-A[i+1]));
        }
        
        for (int i = 1; i < n; ++i) {
            res += abs(A[i] - A[i-1]);
            int tt0 = A[i-1] - A[i] - abs(A[i-1] - A[i]);
            int tt1 = A[i-1] + A[i] - abs(A[i-1] - A[i]);
            int tt2 = -A[i-1] - A[i] - abs(A[i-1] - A[i]);
            int tt3 = -A[i-1] + A[i] - abs(A[i-1] - A[i]);
            
            diff = max({diff, t0+tt3, t1+tt2, t2+tt1, t3+tt0});
            
            t0 = max(tt0, t0);
            t1 = max(tt1, t1);
            t2 = max(tt2, t2);
            t3 = max(tt3, t3);
        }
        
        return res + diff;
    }
};