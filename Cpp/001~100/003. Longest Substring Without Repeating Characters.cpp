class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) return 0;
        int n = s.length(), left = -1, res = 1;
        vector< int > m(128,-1);
        for (int i = 0; i < n; i++) {
            left = max(left, m[s[i]]);
            m[s[i]] = i;
            res = max(res, i-left);   
        }
        return res;
    }
};