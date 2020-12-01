class Solution {
public:
    double getProbability(vector<int>& balls) {
        int N = accumulate(balls.begin(), balls.end(), 0), n = N / 2;
        return dfs(0, 0, 0, 0, 0, balls, n);
    }
    
    double dp[8][50][50][8][8];
    
    double dfs(int i, int l, int r, int cl, int cr, vector<int> &balls, int n) {
        if (i == balls.size()) {
            return (l == r && cl == cr) ? 1.0 : 0; 
        }
        if (dp[i][l][r][cl][cr] != 0) return dp[i][l][r][cl][cr];
        double ret = 0;
        double a = C(2*n - l - r, balls[i]);
        for (int k = 0; k <= balls[i]; ++k) {
            int new_l = l+k, new_r = r+balls[i]-k;
            if (new_l > n) break;
            if (new_r > n) continue;
            int new_cl = cl + (k == 0 ? 0 : 1);            
            int new_cr = cr + (k == balls[i] ? 0 : 1);        

            double b = C(n - l, k);
            double c = C(n - r, balls[i]-k);
            ret += dfs(i+1, new_l, new_r, new_cl, new_cr, balls, n) / a * b * c;
        }
        return dp[i][l][r][cl][cr] = ret;
    }
    
    double C(int n, int i) {
        if (i > n) return 0;
        if (i == 0) return 1;
        return C(n-1, i-1) + C(n-1, i);
    }
};