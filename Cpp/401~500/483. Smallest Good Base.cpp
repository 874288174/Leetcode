/*
tip
n = a^(k-1) + a^(k-2) + ... + 1
a^(k-1) + a^(k-2) + ... + 1 > a^(k-1)
a^(k-1) + a^(k-2) + ... + 1 < (a+1)^(k-1)
*/

class Solution {
public:
    using ull = unsigned long long;
    string smallestGoodBase(string nstr) {
	    ull n = stoull(nstr);
	    for (int k = 63; k >= 3; k--) {
		    ull result = try_k(n, k);
		    if (result > 0) return to_string(result);
	    }
	    return to_string(n-1);
    }
private:
    ull try_k(ull n, int k) {
	    double ord = 1.0 / (k-1);
	    double root = pow(n, ord);
	    ull a = floor(root);
	    if (a < 2) return 0;
	    ull sum = 1;
	    for (int i = 0; i < k-1; i++) sum = sum * a + 1;
	    if (sum != n) return 0;
	    return a;
    }
};