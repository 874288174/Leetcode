class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int MAX = nums[0], MIN = nums[0];
        for (auto i = nums.begin()+1; i != nums.end(); i++) {
            int a = (*i)*MAX, b = (*i)*MIN;
            if (a < b) swap(a, b);
            MAX = max(a, *i);
            MIN = min(b, *i);
            res = max(res, MAX);
        }
        return res;
    }
};