class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 1; i < n; i++){
            if (nums[i-1] == nums[i])
                return true;
        }
        return false;
    }
};



///////////////////////////////////////////////////////////////////////

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> My_set;
        for (auto &i: nums) {
            if (My_set.count(i)) return true;
            else My_set.insert(i);
        }
        return false;
    }
};