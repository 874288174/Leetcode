class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size(), res = 1;
        vector<int> L(n), v;
        for (int i = 0; i < n; ++i) {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            L[i] = it - v.begin() + 1;
            if (it == v.end()) v.push_back(nums[i]);
            else *it = nums[i];
        }

        v.clear();
        for (int i = n-1; i >= 0; --i) {
            auto it = lower_bound(v.begin(), v.end(), nums[i]);
            if (L[i] > 1 && it-v.begin() > 0) 
                res = max(res, (int)(it-v.begin()) + L[i]);
            if (it == v.end()) v.push_back(nums[i]);
            else *it = nums[i];
        }
        return n - res;
    }
};