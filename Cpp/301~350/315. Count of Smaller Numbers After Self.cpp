class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)  v[i] = {nums[i], i}; 
        merge_sort(v.begin(), v.end(), res);  
        return res;
    }
private:
    void merge_sort(vector<pair<int, int>>:: iterator l, vector<pair<int, int>>:: iterator r, 
            vector<int> &res) {
        if (l+1 < r) {
            auto mid = l + (r-l)/2;
            merge_sort(l, mid, res);
            merge_sort(mid, r, res);
            merge(l, r, res);
        }  
    }
    
    void merge(vector<pair<int, int>>:: iterator l, vector<pair<int, int>>:: iterator r, 
            vector<int> &res) {
        vector<pair<int, int>> t(r-l);
        int cnt = 0;
        auto mid = l + (r-l)/2, p = l, q = mid;
        while (p < mid || q < r) {
            if (p < mid && q < r) {
                if (q->first >= p->first) t[cnt++] = *q++;
                else {
                    res[p->second] += r-q;
                    t[cnt++] = *p++;
                }
            }
            else if (p < mid)  t[cnt++] = *p++;
            else t[cnt++] = *q++;
        }
        int k = 0;
        for(auto i = l; i < r; i++) *i = t[k++];
    }
};