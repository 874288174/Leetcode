class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size(), m = nums2.size();
        vector<int> res;
        for (int k1 = max(k-m, 0); k1 <= min(k, n); ++k1) {
            auto s1 = maxKsequence(nums1, k1);
            auto s2 = maxKsequence(nums2, k-k1);
        
            vector<int> temp;
            auto i1 = s1.begin(), end1 = s1.end();
            auto i2 = s2.begin(), end2 = s2.end();
            while (i1 != end1 || i2 != end2)
               temp.push_back(lexicographical_compare(i1, end1, i2, end2) ? *i2++ : *i1++);
            res = max(res, temp);
        }
        return res;
    }

    vector<int> maxKsequence(const vector<int> &nums, int k) {
        int drop = nums.size() - k;
        vector<int> stk;
        for (int i : nums) {
            while (drop && !stk.empty() && stk.back() < i) {
                stk.pop_back();
                drop--;
            }
            stk.push_back(i);
        }
        stk.resize(k);
        return stk;
    }
};