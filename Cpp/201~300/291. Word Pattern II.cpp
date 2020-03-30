class Solution {
public:
    bool wordPatternMatch(string pattern, string str) {
        v.resize(26, "");
        return dfs(0, pattern.size(), 0, str.size(), pattern, str);
    }
private:
    vector<string> v;
    unordered_set<string> myset;

    bool dfs(int i, int n, int j, int m, string &pattern, string &str) {
       if (i == n || j == m) {
           return i == n && j == m;
       }
       int c = pattern[i] - 'a';
       if (v[c] != "") {
           int len = v[c].size();
           if (m-j < len || str.substr(j, len) != v[c]) return false;
           return dfs(i+1, n, j+len, m, pattern, str);
       }
       for (int k = j+1; k <= m; ++k) {
           v[c] = str.substr(j, k-j);
           if (myset.count(v[c])) continue;
           myset.insert(v[c]);
           if (dfs(i+1, n, k, m, pattern, str)) return true;
           myset.erase(v[c]);
       }
       v[c] = "";
       return false;
    }
};