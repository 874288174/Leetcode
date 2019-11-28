class Solution {
public:
    Solution(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m[nums[i]].push(i);
        }
    }
    
    int pick(int target) {
        queue<int> &q = m[target];
        int ret = q.front();
        q.pop();
        q.push(ret);
        return ret;
    }

private:
    unordered_map<int, queue<int>> m;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */