class Solution {
public:
    int numTeams(vector<int>& rating) {
        int res = 0;
        for (auto i = 1; i < rating.size() - 1; ++i) {
            int less[2] = {}, greater[2] = {};
            for (auto j = 0; j < rating.size(); ++j) {
                if (rating[i] < rating[j])
                    ++less[j > i];
                if (rating[i] > rating[j])
                    ++greater[j > i];
            }
            res += less[0] * greater[1] + greater[0] * less[1];
        }
        return res;
    }
};








class SolutionOfLeetCode315 {
public:
    using pii = pair<int, int>;
    vector<vector<int>> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pii> v(n);
        vector<vector<int>> res(2, vector<int>(n, 0));
        for (int i = 0; i < n; i++)  v[i] = {nums[i], i}; 
        merge_sort(v.begin(), v.end(), res, true); 
        for (int i = 0; i < n; i++)  v[i] = {nums[i], i}; 
        merge_sort(v.begin(), v.end(), res, false);
        return res;
    }
private:
    void merge_sort(vector<pii>::iterator l, vector<pii>::iterator r,
                    vector<vector<int>> &res, bool IsGreater) {
        if (l+1 < r) {
            auto mid = l + (r-l)/2;
            merge_sort(l, mid, res, IsGreater);
            merge_sort(mid, r, res, IsGreater);
            merge(l, r, res, IsGreater);
        }  
    }
    
    void merge(vector<pii>::iterator l, vector<pii>::iterator r, 
               vector<vector<int>> &res, bool IsGreater) {
        int cnt = 0;
        auto mid = l + (r-l)/2, p = l, q = mid;
        while (p < mid || q < r) {
            if (p < mid && q < r) {
                if (q->first >= p->first) {
                    if (!IsGreater) res[1][p->second] += r-q;
                    IsGreater ? ++q : ++p;
                }
                else {
                    if (IsGreater) res[0][p->second] += r-q;
                    IsGreater ? ++p : ++q;
                }
            }
            else if (p < mid) p++;
            else q++;
        }
        if (IsGreater) inplace_merge(l, mid, r, std::greater<>());
        else inplace_merge(l, mid, r, std::less<>());
    }
};



class Solution {
public:
    int numTeams(vector<int>& rating) {
        //preprocess
        class SolutionOfLeetCode315 A;
        auto temp = A.countSmaller(rating);
        auto &t0  = temp[0], t1 = temp[1];
        
        int n = rating.size(), res = 0;
        vector<int> sorted_rating(rating);
        sort(sorted_rating.begin(), sorted_rating.end());
        
        for (int i = 1; i < n-1; ++i) {
            int pos = lower_bound(sorted_rating.begin(), sorted_rating.end(), rating[i]) 
                      - sorted_rating.begin(); 
            res += t0[i]*(n-1-pos-t1[i]) + t1[i]*(pos-t0[i]);
        }
        return res;
    }
};









