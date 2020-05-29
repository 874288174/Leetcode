class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int index = 2, n = nums.size();
        for (int i = 2; i < n; i++){
            if(nums[index-2] != nums[i]){
                nums[index++] = nums[i];
            }
        }
        return index;
    }
};