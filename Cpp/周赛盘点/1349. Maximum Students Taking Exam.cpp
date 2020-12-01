class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size(), n = seats[0].size(), k = 0;
        vector<vector<int>> f(2, vector<int>(1 << n, -1));
        f[0][0] = 0;

        for (int i = 0; i < m; ++i) {
            auto &pre = f[k], &cur = f[k^1];
            int valid = 0;
            for (auto c : seats[i]) valid = valid * 2 + (c == '.');
            
            for (int j = 0; j < (1 << n); ++j) {
                if ((j & valid) == j && !(j & (j >> 1))) {
                    for (int k = 0; k < (1 << n); ++k) {
                        if (j&(k>>1) || (j>>1)&k || pre[k]==-1) 
                            continue;
                        cur[j]=max(cur[j],pre[k]+__builtin_popcount(j));
                    }
                }
            }
            k ^= 1;
        }
        return *max_element(f[k].begin(), f[k].end());
    }
};
