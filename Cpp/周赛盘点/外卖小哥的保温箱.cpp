#include <bits/stdc++.h>
 
using namespace std;
 
typedef struct {
    int x, y;
    //x为箱子个数，y表示选的这些箱子中原有的保温箱的个数
}mytype;
 
int main() {
    int n, w = 0, ori_w = 0;
    cin >> n;
    vector<int> a(n), b(n);
    
    for(auto &e : a) {cin >> e; ori_w += e;}
    for(auto &e : b) {cin >> e; w += e;} 
    
    vector<mytype> f(w+1, {INT_MAX, 0});
    f[0] = {0, 0};
     
    for (int i = 1; i <= n; ++i) {
        for (int j = w; j > 0; --j) {
            if (j >= b[i-1] && f[j-b[i-1]].x != INT_MAX) {
                if (f[j].x > f[j-b[i-1]].x+1) 
                    f[j] = {f[j-b[i-1]].x+1, f[j-b[i-1]].y + a[i-1]};
                else if (f[j].x == f[j-b[i-1]].x + 1) {
                    f[j].y = max(f[j].y, f[j-b[i-1]].y + a[i-1]);
                }
            }
        }
    }
     
    mytype res = {INT_MAX, 0};
    for (int j = ori_w; j<=w; ++j) {
        if (f[j].x != INT_MAX) {
            if (res.x > f[j].x)
                res = f[j];
            else if (res.x == f[j].x) {
                res.y = max(res.y, f[j].y);
            }
        }
    }
    cout << res.x << " " << ori_w - res.y << endl;
    return 0;
}
