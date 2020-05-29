class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        permutation(nums, 0, nums.size());
    }

    bool permutation(vector<int>& nums, int begin,int end){
        int p = end - 2;
        while(p > -1 && nums[p] >= nums[p+1] ) p--;
        if(p == -1) {
            reverse(nums.begin(),nums.end());
            return false;
        }
        int c = end-1;
        while(nums[p] >= nums[c]) c--;
        swap(nums[p],nums[c]);
        reverse(nums.begin()+p+1,nums.end() );
        return true;
    }
};