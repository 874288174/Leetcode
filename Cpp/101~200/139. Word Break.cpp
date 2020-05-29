class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        size_t n = s.size(), max_len = 0, min_len = INT_MAX; 
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for(auto &i : wordDict) {
            max_len = max(max_len, i.length());
            min_len = min(min_len, i.length());
        }
        vector<bool> f(n+1, false);
        vector<vector<int>> v(n);
        f[n] = true;  
        for (int i = n-1; i >= 0; --i){
            for (int j = i+min_len; j <= n && j-i <= max_len; j++) {
                string word = s.substr(i, j-i);
                if (f[j] && dict.count(word)) {
                    f[i] = true;
                    break;
                }
            }
        }
        return f[0];
    }
};
