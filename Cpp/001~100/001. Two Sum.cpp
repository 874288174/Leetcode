class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> my_map;
        for (int i = 0; i < nums.size(); i++) { 
            if (my_map.count(target - nums[i]) && i != my_map[target - nums[i]]) {
                 return {i, my_map[target - nums[i]]};
            }
            my_map[nums[i]] = i;
        }
    }
};

