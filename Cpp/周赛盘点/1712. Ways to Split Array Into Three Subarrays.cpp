class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    int waysToSplit(vector<int>& nums) {
        ll res = 0;
        int n = nums.size();
        partial_sum(begin(nums), end(nums), begin(nums));
        for (int i = 0, j = 0, k = 0; i < n - 2; ++i) {
            while (j <= i || (j < n - 1 && nums[j] < nums[i] * 2)) ++j;
            while (k < j || (k < n - 1 && 2*nums[k] <= nums[i] + nums[n - 1])) ++k;
            res = (res + k - j) % mod;
        }
        return res;
    }
};












class Solution {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    int waysToSplit(vector<int>& nums) {
        vector<int> preS;
        partial_sum(nums.begin(), nums.end(), back_inserter(preS));
        int n = preS.size(), Sum = preS.back();
        ll res = 0;
        
        for (int i = 0; i < n; ++i) {
            int left = preS[i];
            auto p = lower_bound(preS.begin()+1+i, preS.end(), 2*left);
            auto q = upper_bound(p, prev(preS.end()), (Sum + left) / 2.0);
            res = (res + q-p) % mod;
        }
        return static_cast<int> (res % mod);
    }
};
