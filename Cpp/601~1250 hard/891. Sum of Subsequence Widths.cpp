class Solution {
public:
    using ll = long long;
    int sumSubseqWidths(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        ll res = 0, mod = 1e9+7, n = arr.size();
        
        vector<ll> pow2(n, 1);
        for(int i = 1; i < n; i++) {
            pow2[i] = (pow2[i-1] * 2) % mod;
        }
        
        for(int i = 0; i < n; i++){
            res = (res + arr[i] * ((pow2[i] - pow2[n-1-i] + mod) % mod)) % mod;
        }
        return static_cast<int> (res);
    }
};