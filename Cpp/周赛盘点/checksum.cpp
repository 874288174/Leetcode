#include <bits/stdc++.h>

using namespace std;
using ll = long long;


class UnionFind {
    vector<int> fa;

public:

    UnionFind(int n) {
        fa.resize(n, -1);
    }

    int find(int i) {
        return fa[i] < 0 ? i : (fa[i] = find(fa[i]));
    }

    void connect(int x, int y) {
        int fax = find(x), fay = find(y);
        if (fax != fay) {
            fa[fax] += fa[fay];
            fa[fay] = fax;
        }
    }
};

long long work() {
    int n;
    cin >> n;

    int useless;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> useless;

    vector<tuple<int, int, int>> edges;
    ll tot = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int b;
            cin >> b;
            tot += b;
            edges.emplace_back(b, i, n + j);
        }
    }
    sort(edges.rbegin(), edges.rend());
    UnionFind uf(n * 2);

    for (int i = 0; i < n; ++i) cin >> useless;
    for (int i = 0; i < n; ++i) cin >> useless;

    ll remove = 0;
    for (auto [weight, u, v] : edges) {
        if (uf.find(u) == uf.find(v)) continue;
        remove += weight;
        uf.connect(u, v);
    }
    return tot - remove;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) {
        printf("Case #%d: %lld\n", i, work());
    }
}

