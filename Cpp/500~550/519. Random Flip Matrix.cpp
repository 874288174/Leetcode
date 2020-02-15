class Solution {
public:
    Solution(int n_rows, int n_cols) : n(n_rows), m(n_cols) {
        reset();
    }
    
    vector<int> flip() {
        int used_id = rand() % (sz--);
        int unused_id = mp.count(used_id) ?  mp[used_id] : used_id;
        mp[used_id] = mp.count(sz) ? mp[sz] : sz;
        return {unused_id / m, unused_id % m};
        
    }
    
    void reset() {
        mp.clear();
        sz = n * m;
    }
    
private:
    int n, m, sz;
    unordered_map<int, int> mp;  //<used, not used>
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n_rows, n_cols);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */