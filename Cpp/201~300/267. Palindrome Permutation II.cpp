class Solution {
public:
    vector<string> generatePalindromes(string s) {
        for (auto &c : s)  m[c]++;
        int cnt = 0, n = s.length();
        char mid;
        for (auto &i : m) if (i.second % 2) { 
            if (++cnt > 1) return res;
            else mid = i.first;
        }
        if (cnt == 1) m[s[n/2] = mid]--;
        dfs(0, n, s);
        return res;
    }
private:        
    unordered_map<char, int> m;
    vector<string> res;
    
    void dfs(int i, int n, string &s) {
        if (i == n/2)  res.push_back(s);
        else for (auto &it : m) if (it.second >= 2) {
            s[i] = s[n-1-i] = it.first;
            it.second -= 2;
            dfs(i+1, n, s);
            it.second += 2;
        }
    }
};