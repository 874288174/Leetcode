class Solution {
public:
    int candy(vector<int>& ratings) {
        int N = ratings.size();
        vector< int > nums(N, 1);
        for (int i = 1; i < N; i++) if (ratings[i] > ratings[i-1]) {
            nums[i] = nums[i-1]+1;
        }
        int res = nums[N-1];
        for (int i = N-2; i >= 0; i--) {
            if (ratings[i] > ratings[i+1]) 
               nums[i] = max(nums[i+1]+1, nums[i]);
            res += nums[i];
        }
        return res;
    }
};