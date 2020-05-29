class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        vector<vector<int>> res;
        dfs(1, 0, k, n, path, res);
        return res;
    }
private:
    void dfs(int i, int cur, int k, int n, vector<int> &path, vector<vector<int>> &res) {
        if (cur == k && n == 0) {
            res.push_back(path);
            return;
        }
        for (int j = i; j <= 9 && n-j >= 0; j++) {
            path.push_back(j);
            dfs(j+1, cur+1, k, n-j, path, res);
            path.pop_back();
        }
    }
};