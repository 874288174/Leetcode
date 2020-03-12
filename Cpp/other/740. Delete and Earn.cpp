class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = 10001;
        vector<int> v(n, 0);
        for (int i : nums) v[i] += i;

        int take = 0, skip = 0;
        for (int i = 0; i < n; i++) {
            int temp = skip + v[i];
            skip = max(skip, take);
            take = temp;
        }
        return max(take, skip);
    }
};