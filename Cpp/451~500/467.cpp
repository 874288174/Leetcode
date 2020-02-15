class Solution {
public:
    int findSubstringInWraproundString(string p) {
        vector<int> v(26, 0);
        int len = 0;
        for (int i = 0; i < p.size(); i++) {
            int cur = p[i] - 'a';
            if (i > 0 && p[i - 1] != (cur + 26 - 1) % 26 + 'a') len = 0;
            v[cur] = max(v[cur], ++len);
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};