class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp{{0, 1}};
        int sum = 0, res = 0, sz = nums.size();
        for (int i = 0; i < sz; i++) {
            sum += nums[i];
            res += (mp.count(sum-k) ? mp[sum-k] : 0);
            ++mp[sum];
        }
        return res;
        
    }
};