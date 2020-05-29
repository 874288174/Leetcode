class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size(), m = nums[0].size();
        if (n*m != r*c) return nums;
        vector<vector<int>> res;
        vector<int> temp;
        int cnt = 0;
        for (auto &v : nums) {
            for (auto &i : v) {
                temp.push_back(i);
                if (++cnt % c == 0) {
                    res.push_back(temp);
                    temp.clear();
                }
            }
        }
        return res;
    }
};