class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), res = 0, sum = 0;
        unordered_map<int, int> mp{{0, -1}};
        for (int i = 0; i < n; ++i){
            nums[i] == 0 ? ++sum : --sum;
            if (mp.count(-sum)) res = max(res, i-mp[-sum]);
            else mp[-sum] = i;            
        }
        return res;
    }
};