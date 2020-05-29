class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(res, path, nums, 0);
        return res;
    }
    
    void dfs(vector<vector<int>> &res, vector<int> &path, vector<int>& nums, int cur) {
        if (path.size() > 1) res.push_back(path);
        unordered_set<int> hash;
        for (int i = cur; i < nums.size(); ++i) {
            if ((path.empty() || nums[i] >= path.back()) && !hash.count(nums[i])) {
                path.push_back(nums[i]);
                dfs(res, path, nums, i + 1);
                path.pop_back();
                hash.insert(nums[i]);
            }
        }
    }
};