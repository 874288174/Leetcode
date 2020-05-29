class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size(), res = 1;
        vector<int> f(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                   f[i] = max(f[j]+1, f[i]);
                   res = max(res, f[i]);
                }
            }
        }
        return res;
    }
};


////////////////////////////////
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto &i : nums) {
            auto it = lower_bound(res.begin(), res.end(), i);
            if (it == res.end()) res.push_back(i);
            else *it = i;
        }
        return res.size();
    }
};