class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length(), m = t.length(), j = 0;
        for (int i = 0; i < n; i++) {
            while (j < m && t[j] != s[i]) j++;
            if (j++ == m) return false;
        }
        return true;
    }
};




class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> mp;
        for (int i = 0; i < t.size(); ++i) {
            mp[t[i]].push_back(i);
        }
        int pos = 0;
        for (auto c : s) {
            auto it = lower_bound(mp[c].begin(), mp[c].end(), pos);
            if (it == mp[c].end()) return false;
            pos = *it + 1;
        }
        return true;
    }
};