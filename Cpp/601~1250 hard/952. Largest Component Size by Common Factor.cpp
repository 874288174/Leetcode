class Solution {
public:
    int fa[100005], cnt[100005] = {0};
    
    int largestComponentSize(vector<int>& A) {
        for (int i = 0; i < 100005; ++i) fa[i] = i;
        for (auto i : A) {
            int Sqrt = sqrt(i) + 0.5;
            for (int j = 2; j <= Sqrt; ++j) {
                if (i % j == 0) {
                    Union(i, j);
                    Union(i, i/j);
                }
            }
        }
        int res = 0;
        for (auto i : A) {
            res = max(res, ++cnt[find(i)]);
        }
        return res;
    }
    
    int find(int x) {
        return fa[x] == x ? x : (fa[x] = find(fa[x]));
    }
    
    void Union(int x, int y) {
        fa[find(y)] = find(x);
    }
};