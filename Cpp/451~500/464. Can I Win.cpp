class Solution {
public:
    bool canIWin(int M, int T) {
        int S = M*(M+1)/2;
        if (M >= T) return true;
        else if (S < T) return false;
        else if (S == T)  return M%2; 
        else return dfs(M, T, 0, m);        
    }
    
private:
    unordered_map<int, bool> m; 
    //状态0100..11100 能否赢
    bool dfs(int M, int T, int k, unordered_map<int, bool>& m) {
        if (T <= 0)  return false;
        if (m.count(k)) return m[k];
        for (int i = 0; i < M; ++i) {
            if (!(k & 1<<i) && !dfs(M, T-i-1, k | 1<<i, m)) { 
                return m[k] = true;   
            }
        }
        return m[k] = false;
    }
};