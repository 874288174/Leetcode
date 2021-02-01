class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size(), res = 0;
        vector<int> fa(n, -1);
        for (int i = 0; i < n; i += 2) {
            Union(i, i+1, fa);
            Union(row[i], row[i+1], fa);
        }
        
        for (int i = 0; i < n; ++i) {
            if (find(i, fa) == i) {
                res -= fa[i]/2 + 1;
            }
        }
        return res;
    }
    
    void Union(int x, int y, vector<int> &fa) {
        int fax = find(x, fa);
        int fay = find(y, fa);
        if (fax != fay) {
            fa[fay] += fa[fax];
            fa[fax] = fay;
        }
    }
    
    int find(int x, vector<int> &fa) {
        return fa[x] < 0 ? x : (fa[x] = find(fa[x], fa));
    }
};