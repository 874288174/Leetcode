class Solution {
public:
    using pii = pair<int, int>;
    using vecIter = vector<pair<int, int>>::iterator;
    vector<int> countSmaller(vector<int>& nums) {
        if (nums.empty()) return {};
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
        while (p < mid && q < r) {
            if (q->first >= p->first) q++;
            else {
                res[p->second] += r-q;
                p++;
            }
        }
        inplace_merge(l, mid, r, greater<pii>());
    }
};





class Solution {
public:
    using pii = pair<int, int>;
    
    vector<int> countSmaller(vector<int>& v) {
        n = v.size();
        vector<int> res(n), pos(n);
        bits.resize(n+1, 0);
        
        vector<pii> t(n);
        for (int i = 0; i < n; ++i) {
            t[i] = pii{v[i], i};
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < n; ++i) {
            pos[t[i].second] = i;
        }
        
        for (int i = n-1; i >= 0; i--) {
            update(pos[i], 1);
            res[i] = sumRange(pos[i]);
        }
        
        return res;
    }
    
private:
    vector<int> bits;
    int n;
    
    int bitset (int x) {return x & (-x);}
    
    void update(int i, int val) {
        int diff = val - nums[i];
        nums[i++] = val;
        while (i <= n){
            bits[i] += diff;
            i += bitset(i);
        }
    }
      
    int sumRange(int i) {
        int res = 0;
        while (i) {
            res += bits[i];
            i -= bitset(i);
        }
        return res;
    }
};







class Solution {
public:
    using pii = pair<int, int>;
    int n;
    vector<long long> tree;
    
    vector<int> countSmaller(vector<int>& v) {
        n = v.size();
        vector<int> res(n), pos(n);
        tree.resize(n + n);
        
        vector<pii> t(n);
        for (int i = 0; i < n; ++i) {
            t[i] = pii{v[i], i};
        }
        sort(t.begin(), t.end());
        for (int i = 0; i < n; ++i) {
            pos[t[i].second] = i;
        }
        
        for (int i = n-1; i >= 0; i--) {
            update(pos[i], 1);
            res[i] = sumRange(0, pos[i]-1);
        }
        return res;
    }
    
    void update(int i, int val) {
        i += n;
        tree[i] = val;
        while (i > 0) {
            tree[i>>1] = tree[i] + tree[i^1];
            i >>= 1;
        }
    }
    
    int sumRange(int i, int j) {
        int res = 0;
        i += n;
        j += n;
        
        for (; i <= j; i >>= 1, j >>= 1) {
            if (i&1)    res += tree[i++];
            if (!(j&1)) res += tree[j--];
        }
        return res;
    }
};