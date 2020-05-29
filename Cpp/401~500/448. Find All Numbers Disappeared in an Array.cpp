/*
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (i != nums[i]-1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i != nums[i]-1) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int m = abs(nums[i])-1; // index start from 0
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        vector<int> res;
        for(int i = 0; i < n; i++) {
            if (nums[i] > 0) res.push_back(i+1);
        }
        return res;
    }
};