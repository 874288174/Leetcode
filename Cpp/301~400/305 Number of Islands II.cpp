class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        vector<vector<int>> dirs{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
        vector<int> fa(m*n, -1), res;
        // -1 water, other land标签
        int cnt = 0;
        
        for (auto &v : positions) {
            int id = n*v[0] + v[1];
            if (fa[id] == -1) {
                fa[id] = id;
                ++cnt;
            }
            for (auto dir : dirs) {
                int x = v[0]+dir[0], y = v[1]+dir[1], cur_id = n*x + y;
                if (x < 0 || x >= m || y < 0 || y >= n || fa[cur_id] == -1) continue;
                int p = find(fa, cur_id), q = find(fa, id);
                if (p != q) {
                    fa[p] = q;
                    --cnt;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
    
private:
    int find(vector<int> &fa, int x) {
        return (x == fa[x]) ? x : (fa[x] = find(fa, fa[x]));
    }
};