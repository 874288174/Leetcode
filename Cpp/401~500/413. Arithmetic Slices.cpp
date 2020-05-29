class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) return 0;
        int cnt = 0, res = 0;
        for(int i = 2; i < A.size(); i++) {
            if (A[i-1] - A[i-2] == A[i] - A[i-1]) res += ++cnt;
            else cnt = 0;
        }
        return res;
    }
};
