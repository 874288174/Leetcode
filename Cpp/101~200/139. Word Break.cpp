class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(), max_len = 0, min_len = INT_MAX; 
        unordered_set<string> dict;
        for(auto &i : wordDict) {
            max_len = max(max_len, (int)i.length());
            min_len = min(min_len, (int)i.length());
            dict.insert(i);
        }
        if (dict.empty()) return false;
        vector<bool> f(n+1, false);
        f[0] = true;
        for (int i = 1; i <= n; ++i){
            for (int j = i-min_len; j >= max(0, i-max_len); --j) {
                if (f[j] && dict.find(s.substr(j, i-j)) != dict.end()) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[n];
    }
};