class Solution {
public:
    using vecIter = vector<long long>::iterator;
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long long> sum(n+1, 0);
        for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + nums[i-1];
        merge_sort(sum.begin(), sum.end(), lower, upper);
        return res;
    }
private:
    int res = 0;

    void merge_sort(vecIter l, vecIter r, int lower, int upper) {
        if (l + 1 < r) {
            auto mid = l + distance(l, r) / 2;
            merge_sort(l, mid, lower, upper);
            merge_sort(mid, r, lower, upper);
            merge(l, r, lower, upper);
        }
    }
    
    void merge(vecIter l, vecIter r, int lower, int upper) {
        auto mid = l + distance(l, r) / 2;
        auto p = l, Low = mid, Up = mid;
        while (p < mid) {
            while (Low < r && *Low - *p < lower) ++Low;
            while (Up < r && *Up - *p <= upper) ++Up;
            res += Up-Low;
            p++;
        }
        inplace_merge(l, mid, r);
    }
};