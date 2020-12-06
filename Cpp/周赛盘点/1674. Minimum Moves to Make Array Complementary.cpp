class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size(), N = limit*2 + 2;
        vector<int> d(N), cnt(N);

        for (int i = 0; i + i < n; ++i) {
            ++cnt[nums[i] + nums[n - i - 1]];
            ++d[1 + min(nums[i], nums[n - i - 1])];
            --d[limit + max(nums[i], nums[n - i - 1]) + 1];
        }
        int res = n * 2, Sum = 0;

        for (int K = 2; K < N; ++K) {
            Sum += d[K];
            res = min(res, n - Sum - cnt[K]);
        }
        return res;
    }
};