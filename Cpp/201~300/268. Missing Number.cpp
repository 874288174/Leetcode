class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), res = n;
        for(int i = 0; i < n; i++) res ^= i ^ nums[i];
        return res;
    }
};


///////////////////////////////////////////////
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size()-1;
        while (left < right) {
            int mid = left + (right-left)/2;
            if (nums[mid] == mid) left = mid+1;
            else right = mid;
        }
        if (nums[left] == left) return nums.size();
        else return nums[left]-1;
    }
};