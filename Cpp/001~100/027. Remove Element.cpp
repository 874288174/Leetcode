class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int indix = 0;
        for (int i = 0; i < nums.size(); i++){
           if (nums[i] != val)
              nums[indix++] = nums[i];
        }
        return indix;
    }
};