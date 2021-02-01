class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        strs.erase(unique(strs.begin(), strs.end()), strs.end());
        int n = strs.size(), res = 0;

        vector<int> fa(n, -1);
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (check(strs[i], strs[j])) {
                    Union(i, j, fa);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (find(i, fa) == i) ++res;
        }
        return res;
    }
    
    bool check(string &a, string &b) {
        int n = a.size(), cnt = 0;
        for (int i = 0; i < n; ++i) 
            if (a[i] != b[i]) 
                if (++cnt > 2) return false;
        return true;
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