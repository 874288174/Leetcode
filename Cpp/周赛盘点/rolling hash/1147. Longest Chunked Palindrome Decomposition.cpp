class Solution {
    using ul = unsigned long;
    ul p = 31,  m = 1e9 + 7;
    int helper(const string_view& s, int l, int r) {
        if (l >= r) return 0;
        ul prefix_hash = 0, suffix_hash = 0, pow = 1;
        for (int i = 0; i < (r - l) / 2; ++i) {
            prefix_hash = (prefix_hash + s[l + i] * pow) % m;
            suffix_hash = (suffix_hash * p + s[r - i - 1]) % m;
            pow = (pow * p) % m;
            if (prefix_hash == suffix_hash) {
                if (s.substr(l, i + 1) == s.substr(r - i - 1, i + 1)) {
                    return 2 + helper(s, l + i + 1, r - i - 1);   
                }
            }
        }
        return 1;
    }
public:
    int longestDecomposition(string text) {
        return helper(text, 0, text.size());
    }
};






class Solution {
    int longestDecomposition(string S) {
        int res = 0, n = S.length();
        string l, r;
        for (int i = 0; i < n; ++i) {
            l = l + S[i], r = S[n - i - 1] + r;
            if (l == r) {
                ++res;
                l = r = "";
            }
        }
        return res;
    }
};