class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size(), res = n;
        vector<int> fa(n);
        for (int i = 0; i < n; i++) fa[i] = i;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) if (M[i][j]) {
                int fa0 = find(fa, i);
                int fa1 = find(fa, j);
                if (fa0 != fa1) {
                    fa[fa0] = fa1;
                    res--;
                }
            }
        }
        return res;
    }
    
private:
    int find(vector<int> &fa, int x) {
        return x == fa[x] ? x : (fa[x] = find(fa, fa[x]));
    }
};