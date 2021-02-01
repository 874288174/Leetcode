class Solution {
public:
    using ll = long long;
    
    ll check(ll n) {
        ll res = 0;
        while (n) {
            res += (n /= 5);
        }
        return res;
    }
    
    int preimageSizeFZF(int K) {
        int a = low(K);
        if (a == -1) return 0;
        int b = upper(K);
        return b - a;
        
    }
    
    ll low(int K) {
        ll l = 0, r = LLONG_MAX;
        while (l < r) {
            ll mid = l + (r-l) / 2;
            if (check(mid) < K) l = mid+1;
            else r = mid;
        }
        return check(l) == K ? l : -1;
    }
    
    ll upper(int K) {
        ll l = 0, r = LLONG_MAX;
        while (l < r) {
            ll mid = l + (r-l) / 2;
            if (check(mid) <= K) l = mid+1;
            else r = mid;
        }
        return l;
    }
};