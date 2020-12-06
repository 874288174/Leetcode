class Solution {
private:
    array<int, 61> vis;
    array<array<int, 4>, 61> bound;
    
    int n, m;
    
    bool dfs(vector<vector<int>>& v, int color) {
        if (vis[color] != 0) return vis[color] == -1;
        const auto &arr = bound[color];
        if (arr[0] == INT_MAX) return true;

        vis[color] = 1;
        
        for (int i = arr[0]; i <= arr[1]; ++i) {
            for (int j = arr[2]; j <= arr[3]; ++j)
                if (v[i][j] != color && !dfs(v, v[i][j])) 
                    return false;
        }
        vis[color] = -1;
        
        return true;
    }
    
    
public:
    bool isPrintable(vector<vector<int>>& v) {
        bound.fill(array<int, 4> {INT_MAX, INT_MIN, INT_MAX, INT_MIN});
        n = v.size(), m = v[0].size();
        for (int i = 0; i < n; ++i) { 
            for (int j = 0; j < m; ++j) {
                auto &arr = bound[v[i][j]];
                arr[0] = min(arr[0], i);
                arr[1] = max(arr[1], i);
                arr[2] = min(arr[2], j);
                arr[3] = max(arr[3], j);
            }
        }
        for (int color = 1; color <= 60; ++color) 
            if (!dfs(v, color)) 
                return false;
        return true;
    }
};