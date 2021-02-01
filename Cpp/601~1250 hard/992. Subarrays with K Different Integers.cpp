class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A, K) - atMostK(A, K-1);
    }
    
    int atMostK(vector<int> &A, int K) {
        if (K == 0) return 0;
        int i = 0, j = 0;
        int n = A.size(), ret = 0;
        unordered_map<int, int> mp;
        while (j < n) {
            while (i < n && mp.size() + !(mp.count(A[i])) <= K) {
                ++mp[A[i++]];
            }
            ret += i-j;
            if (!--mp[A[j]]) mp.erase(A[j]);
            ++j;
        }
        return ret;
    }
};