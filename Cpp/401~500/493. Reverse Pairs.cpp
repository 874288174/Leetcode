class Solution {
public:
    using vecIter = vector<int>::iterator;

    int reversePairs(vector<int>& v) {
        return merge_sort(v.begin(), v.end()); 
    }


    int merge_sort(vecIter l, vecIter r) {
        int res = 0;
        if (l+1 < r) {
            auto mid = l + (r-l)/2;
            res = merge_sort(l, mid) + merge_sort(mid, r);
            res += merge(l, r);
        }
        return res;
    }

    int merge(vecIter l, vecIter r) {
        int res = 0;
        auto mid = l + (r-l)/2, p = l, q = mid;
        for (auto i = l; i < mid; i++) {
            while (q < r && *i > *q * 2LL) q++;
            res += distance(mid, q);
        }
        inplace_merge(l, mid, r);
        return res;
    }
};