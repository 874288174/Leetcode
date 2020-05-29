class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;
        for (const auto &s : paths) {
            stringstream ss(s);
            string root, file;
            ss >> root;
            while (ss >> file) {
               auto pos = file.find('(');
               string content = file.substr(pos);
               mp[content].push_back(root + "/" + file.substr(0, pos));
            }
        }
        vector<vector<string>> res;
        for (auto i : mp) {
            if (i.second.size() > 1) {
               res.push_back(i.second);
            }
        }
        return res;
    }
};