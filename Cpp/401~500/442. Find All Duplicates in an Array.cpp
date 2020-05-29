class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (i != nums[i]-1 && nums[i] != nums[nums[i]-1]) {
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (i != nums[i]-1) {
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};


