class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int n) {
        if (n <= 0) return true;
        int N = v.size();
        for(int i = 0; i < N; i++) {
            if ((!i || !v[i-1]) && !v[i] && (i == N-1 || !v[i+1])) {
                if (--n == 0) return true;
                v[i] = 1;
            }
        }
        return false;
    }
};