class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0, n = g.size(), m = s.size();
        int res = 0;
        while (i < n && j < m) {
            if (g[i] <= s[j++]) {
                res++;
                i++;
            }
        }
        return res;
    }
};