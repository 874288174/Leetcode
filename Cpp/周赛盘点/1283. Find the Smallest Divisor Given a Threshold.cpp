class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = INT_MAX;
        while (l < r) {
            int mid = l + (r-l)/2, sum = 0;
            for (double i : nums) sum += ceil(i / mid);
            if (sum > threshold) l = mid+1; 
            else r = mid;
        }
        return l;
    }
};
