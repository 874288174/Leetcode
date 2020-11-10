class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n = picture.size(), m = picture[0].size();
        unordered_map<string, int> mp;
        vector<int> b(m);

        for (int i = 0; i < n; ++i) {
            string s;
            int cnt = 0;
            for (int j = 0; j < m; ++j) {
                s += picture[i][j];
                if (picture[i][j] == 'B') {
                    ++b[j], ++cnt;
                }
            }
            if (cnt == N) ++mp[s];
        }

        int res = 0;
        for (auto &psi : mp) {
            if (psi.second == N) {
                for (int j = 0; j < m; ++j) {
                    if (psi.first[j] == 'B' && b[j] == N)
                        res += N;
                }
            }
        }
        
        return res;
    }
};