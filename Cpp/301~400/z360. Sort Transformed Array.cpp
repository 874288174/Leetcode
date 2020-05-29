class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        vector<int> res;
        double mid = -b / (2.0*a);
        int high = lower_bound(nums.begin(), nums.end(), mid)-nums.begin(), low = high-1;
        for (int i = 0; i < n; i++) {
            int x;
            if (low >= 0 && (high == n || nums[high]+nums[low] > 2*mid)) x = nums[low--];
            else x = nums[high++];
            res.push_back((a*x+b)*x + c);
        }
        if (a < 0) reverse(res.begin(), res.end());
        return res;
    }
};