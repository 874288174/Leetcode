class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        vector<vector<int>> v(26, vector<int> {-1});
        for (int i = 0; i < n; ++i) {
            v[s[i]-'A'].push_back(i);
        }
        
        long long res = 0, mod = 1e9 + 7;
        for (auto &t : v) {
            t.push_back(n);
            for (int i = 1; i < t.size()-1; ++i) {
                res = (res + 1ll * (t[i]-t[i-1]) * (t[i+1]-t[i])) % mod; 
            }
        }
        return static_cast<int> (res);
    }
};