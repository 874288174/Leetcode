class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.length();
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = abs(s[i]-t[i]);
        }
        int left = -1, res = 0;
        for (int i = 0; i < n; ++i) {
            if ((maxCost -= v[i]) < 0) {
                while (left < i && maxCost < 0) {
                    maxCost += v[++left];
                }
            }
            res = max(res, i-left);
        }
        return res;
    }
};