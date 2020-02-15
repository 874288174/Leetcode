class Solution {
public:
    vector<int> lexicalOrder(int n) {
        dfs(0, n);
        return res;
    }
    
private:
    vector<int> res;
    void dfs(int i, int n) {
       if (i > n) return;
       for (int j = (i == 0 ? 1 : 0); j <= 9; ++j) {
           int k = i*10 + j;
           if (k <= n) {
               res.push_back(k);
               dfs(k, n);
           }
       } 
    }
};