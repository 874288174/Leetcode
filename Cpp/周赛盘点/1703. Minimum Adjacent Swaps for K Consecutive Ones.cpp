class Solution {
public:
    int minMoves(vector<int>& nums, int k) {
        vector<long> A, B{0};
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i]) A.push_back(i);
        }
        partial_sum(A.begin(), A.end(), back_inserter(B));
        
        long n = A.size(), res = 2e9;

        for (int i = 0; i < n - k + 1; ++i)
            res = min(res, B[i + k] - B[k / 2 + i] - B[(k + 1) / 2 + i] + B[i]);
        return res - (k / 2) * ((k + 1) / 2);
    }
};