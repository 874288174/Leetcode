class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> My_set;
        for (int i = 0; i < nums.size(); i++){
            if (My_set.count(nums[i])) return true;
            My_set.insert(nums[i]);
            if(i >= k) My_set.erase(nums[i-k]);
        }
        return false;
    }
};



////////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> My_map;
        for (int i = 0; i < nums.size(); i++){
            if (My_map.count(nums[i]) && i-My_map[nums[i]] <= k) return true;
            My_map[nums[i]] = i;
        }
        return false;
    }
};