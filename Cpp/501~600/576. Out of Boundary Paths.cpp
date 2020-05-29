class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        return dfs(i, j, N-1, m, n);
    }
    
private:
    vector<int> dx{-1, 1, 0, 0}, dy{0, 0, -1, 1};
    const int MOD = 1000000007;
    map<tuple<int, int, int>, long> mp;
    
    int dfs(int x, int y, int z, int n, int m) {
        if (z < 0) return 0;
        auto t = make_tuple(x, y, z);
        if (mp.count(t)) return mp[t];
        long ret = 0;
        for (int k = 0; k < 4; ++k) {
            int xx = x + dx[k], yy = y + dy[k];
            if (xx < 0 || yy < 0 || xx >= n || yy >= m) ret++;
            else ret += dfs(xx, yy, z-1, n, m); 
        }
        return mp[t] = (ret %= MOD);
    }
};