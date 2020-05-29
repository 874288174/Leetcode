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