class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.size(), max_len = 0, min_len = INT_MAX; 
        unordered_set<string> dict;
        for(auto &i : wordDict) {
            max_len = max(max_len, i.length());
            min_len = min(min_len, i.length());
            dict.insert(i);
        }
  
        vector<vector<bool>> prev(n+1, vector<bool>(n+1, false));
        vector<bool> f(n+1, false);
        f[0] = true;
        
        for (int i = 1; i <= n; ++i){
            for (int j = i-min_len; j >= 0; --j) {
                if (i-j > max_len) break;
                string word = s.substr(j, i-j);
                if (f[j] && dict.find(word) != dict.end()) {
                    prev[j][i] = f[i] = true;
                }
            }
        }
        
        vector<string> res, path;
        dfs(n, s, path, prev, res);
        return res;
    }
    
private:
    size_t n ,max_len, min_len; 
    
    void dfs(int i, string &s, vector<string> &path, vector<vector<bool>> &prev, vector<string> &res) {
        if (i == 0) {
            string t;
            for (auto iter = path.rbegin(); iter != path.rend(); iter++)
                t += *iter+' ';
            t.erase(t.end()-1);
            res.push_back(t);
            return;
        }
        else for (int j = i-min_len; j >= 0; --j) {
            if (i-j > max_len) break;
            if (prev[j][i]) {
                path.push_back(s.substr(j, i-j));
                dfs(j, s, path, prev, res);
                path.pop_back();
            }
        }
    }
};



