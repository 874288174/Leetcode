class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size(), m = picture[0].size();
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B') {
                    ++a[i], ++b[j];
                }
            }
        }
        int res = 0;

        for (int i = 0; i < n; ++i) {
            if (a[i] != 1) continue;
            for (int j = 0; j < m; ++j) {
                if (picture[i][j] == 'B' && b[j] == 1) ++res;
            }
        }

        return res;
    }
};