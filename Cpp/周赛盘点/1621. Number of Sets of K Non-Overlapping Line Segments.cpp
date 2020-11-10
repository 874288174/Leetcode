class Solution {
public:
    constexpr static int mod = 1e9 + 7, N = 2050;
 
    int C[N][N];

    void Init () {
        for (int i = 1; i < N; i++) {
            C[i][0] = C[i][i] = 1;
            for (int j = 1; j < i; j++)
                C[i][j] = (C[i-1][j-1]+C[i-1][j]) % mod;
        }
    }



    int numberOfSets(int n, int k) {
        Init();
        return C[n + k - 1][2 * k];
    }
};


class Solution {
public:
    constexpr static int mod=1e9+7, MX=2e3+10;
    int mult(int a,int b){return (1ll*a*b)%mod;}
    int fact[MX],inv[MX],invfact[MX];
    
    void init_INV(){
        fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
        for (int i = 2; i < MX; i++) {
            fact[i] = mult(fact[i - 1], i);
            inv[i] = mult(inv[mod % i], mod - mod / i);
            invfact[i] = mult(invfact[i - 1], inv[i]);
        }
    }
    int ncr(int n,int r){
        if(r > n) return 0;
        return (1LL * fact[n] * invfact[n-r] % mod) * 1LL *invfact[r] % mod;
    }


    int numberOfSets(int n, int k) {
        init_INV();
        return ncr(n + k - 1, 2 * k);
    }

};



class Solution {
public:
    int numberOfSets(int n, int K) {
        vector<vector<int>> dp(n, vector<int>(K + 1));
        int kMod = 1e9 + 7;
        
        dp[1][1] = 1;
        
        for (int i = 2; i < n; i++)
            dp[i][1] = (i + 1) * i / 2;
        
        vector<vector<int>> sum(n, vector<int>(K + 1));
        
        for (int i = 2; i < n; i++) {
            for (int k = 2; k <= K; k++) {
                if (k <= i)
                    sum[i][k] =  (sum[i - 1][k] + dp[i - 1][k - 1]) % kMod;
                dp[i][k] = (sum[i][k] + dp[i - 1][k]) % kMod;         
            }
        }        
        return dp[n - 1][K];
    }
};