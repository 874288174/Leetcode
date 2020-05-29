class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        dfs(0, k, 1, n, v);
        return res;
    }
private:
    void dfs(int cur, int k, int start, int n, vector<int> &v) {
        if (cur == k) {
            res.push_back(v);
            return;
        }
        for (int i = start; i <= n; i++) {
            v.push_back(i);
            dfs(cur+1, k, i+1, n, v);
            v.pop_back();
        }
    }
};