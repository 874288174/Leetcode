class Solution {
public:
    int longestSubstring(string s, int k) {
        int cnt[256] = {0};
        for (auto &c : s)  cnt[c]++;
        bool ok = true;
        for (auto &c : s) if (cnt[c] < k) { 
            c = ' '; 
            ok = false;
        }
        if (ok) return s.length();
        stringstream ss(s);
        int res = 0;
        while (ss >> s) {
            res = max(res, longestSubstring(s, k));
        }
        return res;
    }
};