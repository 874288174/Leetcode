class Solution {
public:
    using ll = long long;
    static const ll mod = 1e9 + 7;
    int distinctSubseqII(string S) {
        ll sum = 1;
        int cnt[26] = {0};
        
        for (auto c : S) {
            ll old = sum;
            sum = ((2*sum - cnt[c-'a']) % mod + mod) % mod; 
            cnt[c-'a'] = old;
        }
        return static_cast<int> ((sum - 1 + mod) % mod);
    }
};