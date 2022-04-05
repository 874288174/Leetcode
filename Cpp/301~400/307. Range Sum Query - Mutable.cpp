class NumArray {
public:
    NumArray(vector<int> &v) {
        n = v.size();
        bits.resize(n+1, 0);
        nums.resize(n, 0);
        for (int i = 0; i < n; i++)
            _update(i, v[i]);
    }

    void update(int i, int val) {
        _update(i, val);
    }

    int sumRange(int i, int j) {
        return sumRange(j+1) - sumRange(i) ;
    }
    
private:
    vector<int> bits, nums;
    int n;
    
    int bitset (int x) {return x & (-x);}
    
    void _update(int i, int val) {
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











class NumArray {
    std::vector<long long> tree;
    int n;
public:
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.resize(n + n);
        for (int i = 0; i <  n; ++i)
            tree[i + n] = nums[i];
        for (int i = n - 1; i >  0; --i){
            tree[i] = tree[i<<1] + tree[(i<<1)+1];
        }
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