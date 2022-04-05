class Solution {
private:
    static constexpr int mod = 1000000007;
    using LL = long long;
public:
    int sumOfFlooredPairs(vector<int>& nums) {
        int upper = *max_element(nums.begin(), nums.end());
        vector<int> cnt(upper + 1);
        for (int i : nums) ++cnt[i];

        vector<int> preSum(upper + 1);
        partial_sum(next(cnt.begin()), cnt.end(), next(preSum.begin()));
        
        LL res = 0;
        for (int y = 1; y <= upper; ++y) {
            if (cnt[y]) {
                for (int d = 1; d * y <= upper; ++d) {
                    res += 1ll * cnt[y] * d * (preSum[min((d + 1) * y - 1, upper)] - preSum[d * y - 1]);
                    res %= mod;
                }
            }
        }
        return static_cast<int> (res);
    }
};
