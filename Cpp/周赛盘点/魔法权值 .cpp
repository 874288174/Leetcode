#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, K, res = 0;
    cin >> n >> K;
    vector<string> strs(n);
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> strs[i];
        v[i] = i;
    }
 
    do {
        string s;
        for (int i : v) s += strs[i];
        int n = s.size(), k = 1;
        vector<int> f(n, 0);
        for (int i = 1, len = 0; i < n;) {
            if (s[i] == s[len]) f[i++] = ++len;
            else if (len) len = f[len-1];
            else f[i++] = 0;
        }
        if (n % (n - f[n-1]) == 0) k = n / (n - f[n-1]);
        if (k == K) ++res;
    } while (next_permutation(v.begin(), v.end()));
    cout << res << "\n";
}