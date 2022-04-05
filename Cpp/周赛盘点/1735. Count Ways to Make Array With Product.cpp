class Solution {
public:
    using ll = long long;
    static const ll mod = 1e9+7, MX=2e4+10;;
    
    Solution() {init_INV();}
    
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
        if (r > n) return 0;
        return (1LL * fact[n] * invfact[n-r] % mod) * 1LL *invfact[r] % mod;
    }

    
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        vector<int> res;
        for (const auto &q : queries) {
            int n = q[0], k = q[1];
            ll sum = 1;
            for (int i = 2; k != 1; ++i) {
                ll cnt = 0;
                while (k % i == 0) {
                    ++cnt;
                    k /= i;
                }
                if (cnt) sum = (sum * ncr(n+cnt-1, n-1)) % mod;
            }
            res.push_back(static_cast<int> (sum));
        }
        return res;
    }
};