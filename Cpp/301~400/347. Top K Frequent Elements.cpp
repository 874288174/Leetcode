class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(auto i : nums) ++counts[i];
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto &k : counts) buckets[k.second].push_back(k.first);
        vector<int> res;
        for(int t = buckets.size()-1; t >= 0; t--) { 
            for(auto i : buckets[t]) {
                res.push_back(i);
                if (res.size() == k) return res;
            }
        }
        return res;
    }
};