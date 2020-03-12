class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& m) {
        vector<vector<int>> mines(N, vector<int> (N));
        for (auto &v : m) mines[v[0]][v[1]] = 1;
        vector<vector<pair<int, int>>> record(N, vector<pair<int, int>> (N));
        // first -   second |
        for (int i = N-1; i >= 0; --i) {
            for (int j = N-1; j >= 0; --j) {
                if (!mines[i][j]) {
                   record[i][j].first = (i != N-1 ? record[i+1][j].first : 0) + 1;
                   record[i][j].second = (j != N-1 ? record[i][j+1].second : 0) + 1;
                }
            }
        }
        int res = 0;
        vector<int> v(N, 0);
        for (int i = 0; i < N; ++i) {
            int cnt = 0;
            for (int j = 0; j < N; ++j) {
                if (!mines[i][j]) {
                   res = max(res, min(min(++cnt, ++v[j]), 
                                      min(record[i][j].first, record[i][j].second)));
                }
                else v[j] = cnt = 0;
            }
        }
        return res;
    }
};