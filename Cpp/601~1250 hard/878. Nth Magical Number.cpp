class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        using ll = long long;
        const ll mod = 1e9 +7;
        ll t = a*b / __gcd(a, b);
        ll l = 1, r = LONG_MAX; 
        while (l < r) {
            ll mid = l + (r-l) / 2;
            ll rk = mid/a + mid/b - mid/t;
            if (rk < n) l = mid+1;  
            else r = mid;
        }
        return static_cast<int> (l % mod);
    }
};