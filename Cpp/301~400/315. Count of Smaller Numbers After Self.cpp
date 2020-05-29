class Solution {
public:
    using pii = pair<int, int>;
    using vecIter = vector<pair<int, int>>::iterator;
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pii> v(n);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)  v[i] = {nums[i], i}; 
        merge_sort(v.begin(), v.end(), res);  
        return res;
}

private:
    void merge_sort(vecIter l, vecIter r, vector<int> &res) {
        if (l+1 < r) {
            auto mid = l + (r-l)/2;
            merge_sort(l, mid, res);
            merge_sort(mid, r, res);
            merge(l, r, res);
        }  
    }
    
    void merge(vecIter l, vecIter r, vector<int> &res) {
        auto mid = l + (r-l)/2, p = l, q = mid;
        while (p < mid || q < r) {
            if (p < mid && q < r) {
                if (q->first >= p->first) q++;
                else {
                    res[p->second] += r-q;
                    p++;
                }
            }
            else if (p < mid)  p++;
            else q++;
        }
        inplace_merge(l, mid, r, greater<pii>());
    }
};
