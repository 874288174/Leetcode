class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& v) {
        int n = v.size(), r = n - 1;
        while (r > 0 && v[r - 1] <= v[r]) --r;
        int res = r;
        for (int l = 0; l < r && (l == 0 || v[l-1] <= v[l]); ++l) {
            while (r < n && v[r] < v[l]) ++r;
            res = min(res, r - l - 1);
        }
        return res;
    }  
};
