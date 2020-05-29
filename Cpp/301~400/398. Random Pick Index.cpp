class Solution {
public:
    Solution(vector<int>& nums) : beg(nums.begin()), end(nums.end()) {}
    
    int pick(int target) {
        int res, n = 0;
        for (auto it = beg; it != end; ++it) {
            if (*it != target) continue;
            if (rand() % ++n == 0) res = distance(beg, it);
        }
        return res;
    }
private:
    vector<int>::iterator beg, end;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */