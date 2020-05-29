class Solution {
public:
    vector< string > res;
    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");  
        return res;
    }
    void dfs(int n, int m, string s){
        if(n < 0|| m < 0 || n > m) return;
        if(!n && !m){
            res.push_back(s); 
            return;
        }
        dfs(n-1, m, s+'(');
        dfs(n, m-1, s+')');
    } 
};