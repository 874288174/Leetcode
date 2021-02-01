class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> v;
        for (int i = 0 ; i < A.size(); i++)
            if (A[i]) v.push_back(i);
        if (v.size() % 3) return {-1, -1};
	    if (v.empty()) return {0, 2};
        int l1 = 0, l2 = v.size() / 3, l3 = l2 * 2;
        int tail0 = A.size() - v.back();
        if (v[l3] - v[l3-1] < tail0 || v[l2] - v[l2-1] < tail0) return {-1,-1};
        
        for (int i = 1; i < l2; i++) {
            int diff = v[i] - v[i-1];
            if (v[l2+i] - v[l2+i-1] != diff || v[l3+i] - v[l3+i-1] != diff) {
                return {-1, -1};
            }
	    }
        return {v[l2-1] + tail0 - 1, v[l3-1] + tail0};
    }
};