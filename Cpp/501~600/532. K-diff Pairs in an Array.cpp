class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if (k < 0) return 0;
        unordered_map<int, int> mp;
        for (auto &i : nums) ++mp[i];
        int res = 0;
        for (auto &i : mp) {
            if (!k && i.second > 1 || k && mp.count(i.first+k)) 
                ++res;
        }
        return res;
    }
};