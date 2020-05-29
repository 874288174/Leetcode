class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = INT_MAX, j = INT_MAX;
        for (auto &a : nums) {
            if (a < i) i = a;
            else if(a != i && a < j) j = a;
            else if(a > j) return true;
        }
        return false;
    }
};