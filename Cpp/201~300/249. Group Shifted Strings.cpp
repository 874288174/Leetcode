class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> m;
        for (auto &s : strings) {
            string t;
            for (auto &c : s) {
                t += char((c-s[0]+26) % 26);
            }
            m[t].push_back(s);
        }
        vector<vector<string>> res;
        for (auto &i : m) res.push_back(i.second);
        return res;
    }
};