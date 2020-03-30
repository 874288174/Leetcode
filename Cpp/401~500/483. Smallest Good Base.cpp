/*
tip
n = k^(m-1) + k ^(m-2) ... * k + 1
n = (1-k^m) / (1-k)
*/

class Solution {
public:
    string smallestGoodBase(string n) {
        using ll = long long int;
        ll num = stoll(n);
        for (int m = log2(num); m >= 1; m--) {
            ll l = 2, r = powl(num, 1.0 / m) + 1;
            while (l < r) {
               ll mid = l + (r-l)/2, sum = 0;
               for (int j = 0; j <= m; ++j) {
                   sum = sum * mid + 1;
               }
               if (sum == num) return to_string(mid);
               else if (sum < num) l = mid + 1;
               else r = mid;
            }
        }
        return "";
    }
};