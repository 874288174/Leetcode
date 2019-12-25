class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& mat) {
        if (mat.empty()) return 0;
        int n = mat.size(), m = mat[0].size();

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i != 0 && mat[i][j] > mat[i-1][j])
                    mp[i*m+j].push_back((i-1)*m+j);
                else if (i != 0 && mat[i][j] < mat[i-1][j])
                    mp[(i-1)*m+j].push_back(i*m+j);
                if (j != 0 && mat[i][j] > mat[i][j-1]) 
                    mp[i*m+j].push_back(i*m+j-1);
                else if (j != 0 && mat[i][j] < mat[i][j-1]) 
                    mp[i*m+j-1].push_back(i*m+j);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                res = max(res, dfs(i*m+j));
            }
        }
        return res;
    }
private:
    unordered_map<int, vector<int>> mp;
    unordered_map<int, int> dp;
    
    int dfs(int i) {
        if (dp.count(i)) return dp[i]; 
        int ret = 1;    
        for (auto j : mp[i]) {
            ret = max(ret, 1 + dfs(j));
        }
        return dp[i] = ret;
    }
    
};
/*
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix[0].size();
        
        vector<vector<int>> dp(n, vector<int>(m, 0));
        std::function<int(int, int)> dfs = [&] (int x, int y) {
            if (dp[x][y]) return dp[x][y];
            vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for (auto &dir : dirs) {
                int xx = x + dir[0], yy = y + dir[1];
                if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
                if (matrix[xx][yy] <= matrix[x][y]) continue;
                dp[x][y] = std::max(dp[x][y], dfs(xx, yy));
            }
            return ++dp[x][y];
        };
        
        int ret = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                ret = std::max(ret, dfs(i, j));
            }
        }
        
        return ret;
    }
};
*/