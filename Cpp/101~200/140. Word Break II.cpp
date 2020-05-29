class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
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
                    v[i].push_back(j);
                }
            }
        }
        dfs(0, n, s, v);
        return res;
    }
private:
    vector<string> res, path;
    
    void dfs(int i, int n, string &s, vector<vector<int>> &v) {
        if (i == n) {
            string s;
            for (auto &i : path) s += (s == "" ? "" : " ") + i;
            res.push_back(s);
        } 
        else {
            for (auto j : v[i]) {
                path.emplace_back(s.substr(i, j-i));
                dfs(j, n, s, v);
                path.pop_back();
            }
        }
    }
};




/////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& t) {
        size_t max_len = 0, min_len = INT_MAX; 
        for(auto &i : t) {
            max_len = max(max_len, i.length());
            min_len = min(min_len, i.length());
        }
        unordered_set<string> wordDict(t.begin(), t.end());
        unordered_map<int, vector<string>> dp{{s.size(), {""}}};
        function<vector<string>(int)> f = [&](int i) {
            if (!dp.count(i))
                for (int j = i+min_len; j <= s.size() && j-i <= max_len; j++)
                    if (wordDict.count(s.substr(i, j-i)))
                        for (auto tail : f(j))
                            dp[i].emplace_back(s.substr(i, j-i) 
                                               + (tail == "" ? "" : ' ' + tail));
            return dp[i];
        };
        return f(0);
    }
};