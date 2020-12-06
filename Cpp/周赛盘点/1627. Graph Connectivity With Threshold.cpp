class Solution {
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        vector<int> fa(n+1, -1);
        for (int i = threshold+1; i <= n; ++i) {
            for (int j = 2; j*i <= n; ++j) {
                Union(i, i*j, fa);
            }
        }
        
        vector<bool> res;

        for (auto &q : queries) {
            int xx = find(q[0], fa);
            int yy = find(q[1], fa);
            res.push_back(xx == yy);
        }
        return res;
    }
    
    int find(int x, vector<int> &fa) {
        return fa[x] < 0 ? x : (fa[x] = find(fa[x],fa));
    }
    
    void Union(int x, int y, vector<int> &fa) {
        int xx = find(x, fa), yy = find(y, fa);
        if (xx == yy) return;
        fa[yy] += fa[xx];
        fa[xx] = yy;
    }
};