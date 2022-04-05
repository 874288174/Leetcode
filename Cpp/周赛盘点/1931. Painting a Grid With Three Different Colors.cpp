class Solution {
public:
  using ll = long long;
  const ll mod = 1e9 + 7;
  int colorTheGrid(int m, int n) {
    vector<string> v;

    for (int i = pow(3, m) - 1; i >= 0; --i) {
      string s(m, 'A');
      for (int j = 0, ii = i; j < m; ++j) {
        s[j] += ii % 3;
        ii /= 3;
      }
      bool ok = true;
      for (int j = 1; j < m; ++j)
        if (s[j] == s[j - 1]) {
          ok = false;
          break;
        }
      if (ok)
        v.push_back(s);
    }

    int N = v.size();
    vector<vector<int>> g(N);

    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        bool ok = true;
        for (int k = 0; k < m; ++k)
          if (v[i][k] == v[j][k]) {
            ok = false;
            break;
          }
        if (ok)
          g[i].push_back(j);
      }
    }

    ll res = 0;

    vector<int> pre(N, 1);
    while (--n) {
      vector<int> cur(N, 0);
      for (int i = 0; i < N; ++i) {
        for (auto j : g[i]) {
          cur[i] = (cur[i] + pre[j]) % mod;
        }
      }
      pre = std::move(cur);
    }
    return static_cast<int>(accumulate(pre.begin(), pre.end(), 0ll) % mod);
  }
};