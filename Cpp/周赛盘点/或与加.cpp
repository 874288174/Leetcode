#include <bits/stdc++.h>
  
using namespace std;
  
int main() {
    long long x, k, i = 0, res = 0;
    cin >> x >> k;
    while (k) {
        while ((x&(1ll<<i)) != 0) ++i;
        if (k&1) res += (1ll<<i);        
        k >>= 1;
        ++i;
    }
    cout << res << "\n";
}