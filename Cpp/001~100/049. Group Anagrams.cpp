class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> My_map;
        int cnt = 0;
        for (auto &i : strs) {
            string s = i;
            sort(s.begin(), s.end());
            auto it = My_map.find(s);
            if (it == My_map.end()) {
                 My_map[s] = cnt++;
                res.push_back({i});
            }
            else res[it->second].push_back(i);
        }
        return res;
    }
};