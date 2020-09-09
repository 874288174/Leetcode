class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(), nums.end());
        int l = 1, r = nums.back();
        while (l < r) {
            int mid = l + (r-l)/2;
            int sum = 0;
            for (auto &i : nums) {
                sum += ceil(1.0 * i / mid);
            }
            if (sum > threshold) l = mid+1; 
            else r = mid;
        }
        return l;
    }
};