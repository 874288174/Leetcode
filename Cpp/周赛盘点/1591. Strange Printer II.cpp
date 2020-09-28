class Solution {

private: 
    vector<int> vis; // visitation state for each color    
    int n, m;
    
    bool dfs(vector<vector<int>>& targetGrid, int color) {
        if(vis[color] == -1) return true;
        if(vis[color] == 1) return false;
        // find bounds
        int l = INT_MAX, r = INT_MIN, u = INT_MAX, d = INT_MIN;
        for(int i = 0; i < n; i ++) 
            for(int j = 0; j < m; j ++) 
                if(targetGrid[i][j] == color) l = min(l, j), r = max(r, j), u = min(u, i), d = max(d, i);
        
        if(l == INT_MAX) return true; // none of this color

        vis[color] = 1;
        
        // now, start exploring inside my maximal rectangle
        for(int i = u; i <= d; i ++)
            for(int j = l; j <= r; j ++)
                if(targetGrid[i][j] != color && !dfs(targetGrid, targetGrid[i][j])) return false;
        
        vis[color] = -1;
        
        return true;
    }
    
    
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        n = targetGrid.size();
        m = targetGrid[0].size();
        vis = vector<int> (61, 0); // 0: didnt open, 1: open, -1: closed
        for(int color = 1; color <= 60; color ++) if(!dfs(targetGrid, color)) return false;
        return true;
    }
};