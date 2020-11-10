class Fancy {
public:
    using ll = long long;
    const ll mod = 1e9 + 7;
    
    Fancy() {}
    
    
    ll inv(ll a){
        ll n = mod-2, res = 1;
        while(n) {
            if (n&1) {
                res = (res*a)%mod;
            }
            n >>= 1;
            a = (a*a) % mod;
        }
        return res;
    }
    
    
    void append(int val) {
        ll p = (mod + val - add) % mod;
        v.push_back((inv(mul)*p) % mod);
    }
    
    void addAll(int inc) {
        add = (add + inc) % mod;
    }
    
    void multAll(int m) {
        add = (add * m) % mod;
        mul = (mul * m) % mod;
    }
    
    int getIndex(int idx) {
        if (idx >= v.size()) return -1;
        else return (v[idx]*mul + add) % mod;
    }
    
    vector<ll> v;
    ll add = 0, mul = 1;
};