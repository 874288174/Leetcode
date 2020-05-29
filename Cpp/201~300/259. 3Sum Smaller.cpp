class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int res = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int j = i+1, k = n-1;
            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum < target) res += k-(j++);
                else  k--; 
            }
        }
        return res;
    }
};