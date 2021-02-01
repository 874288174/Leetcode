class Solution {
public:
    unordered_map<int, int> f(vector<int> &v) {
        int n = v.size();
        unordered_map<int, int> mp;
        for (int i = (1 << n) -1; i >= 0; --i) {
            int sum = 0;
            for (int j = 0; j < n; ++j) {
                if (i & (1<<j)) sum += v[j];
            }
            ++mp[sum];
        }
        return mp;
    }
    
    
    bool splitArraySameAverage(vector<int>& A) {
        if (A.size() <= 1) return false;

        int sum = accumulate(A.begin(), A.end(), 0);
        int N = A.size(), cnt = 1;
        for(int& x : A) x = N*x - sum;
        if (accumulate(A.begin(), A.end(), 0) == 0) ++cnt;
        vector<int> v0{A.begin(), A.begin() + N/2}, v1{A.begin() + N/2, A.end()};
        
        auto mp0 = f(v0), mp1 = f(v1);
        for (auto [i, j] : mp0) {
            if (mp1.count(-i)) {
                if ((cnt -= j*mp1[-i]) < 0) {
                    return true;
                }
            }
        }
        return false;
    }
};