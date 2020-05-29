class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<int> path;
        dfs(2, n, path);
        return res;
    }
private:
    vector<vector<int>> res;
    void dfs(int cur, int n, vector<int> &path) { 
        int Sqrt = sqrt(n)+0.5;
        for (int i = cur; i <= Sqrt; i++) {
           if (n % i == 0) {
               vector<int> temp = path;
               temp.push_back(i);
               dfs(i, n/i, temp);
               temp.push_back(n / i);
               res.push_back(temp);
           } 
        }
    }
};