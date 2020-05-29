class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long long> My_set;
        for (int i = 0; i < nums.size(); i++) {
            auto pos = My_set.lower_bound( (long long)(nums[i])-t );
            if (pos != My_set.end() && *pos - (long long)(nums[i]) <= t)  return true;
            My_set.insert(nums[i]);
            if (i >= k) My_set.erase(nums[i-k]);
        }
        return false;
    }
};