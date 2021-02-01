class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i = 0; i < target.size(); ++i) {
            mp[target[i]] = i;
        }
        
        vector<int> v;
        
        for (int i = 0; i < arr.size(); ++i) {
            auto it = mp.find(arr[i]);
            if (it == mp.end()) continue;
            auto pos = lower_bound(v.begin(), v.end(), it->second);
            if (pos == v.end()) v.push_back(it->second);
            else *pos = it->second;
        }
        
        return target.size() - v.size();
    }
};