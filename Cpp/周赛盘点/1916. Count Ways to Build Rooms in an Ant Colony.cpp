class Solution {
public:
  Solution() { init_INV(); }

  using ll = long long;
  const ll MOD = 1e9 + 7;
  using pil = pair<int, ll>;

  constexpr static int mod = 1e9 + 7, MX = 1e5 + 10;
  int mult(int a, int b) { return (1ll * a * b) % mod; }
  int fact[MX], inv[MX], invfact[MX];

  void init_INV() {
    fact[0] = invfact[0] = fact[1] = invfact[1] = inv[1] = 1;
    for (int i = 2; i < MX; i++) {
      fact[i] = mult(fact[i - 1], i);
      inv[i] = mult(inv[mod % i], mod - mod / i);
      invfact[i] = mult(invfact[i - 1], inv[i]);
    }
  }

  int ncr(int n, int r) {
    if (r > n)
      return 0;
    return (1LL * fact[n] * invfact[n - r] % mod) * 1LL * invfact[r] % mod;
  }

  pil dfs(int i, vector<vector<int>> &v) {
    if (v[i].empty())
      return pil{1, 1};
    vector<pil> t;
    int n = 0;
    for (auto j : v[i]) {
      t.push_back(dfs(j, v));
      n += t.back().first;
    }
    pil res(n + 1, 1);
    for (auto [t, j] : t) {
      res.second = ((res.second * ncr(n, t) % MOD) * j) % MOD;
      n -= t;
    }

    return res;
  }

  int waysToBuildRooms(vector<int> &prevRoom) {
    int n = prevRoom.size();
    vector<vector<int>> v(n);
    for (int i = 0; i < n; ++i) {
      if (prevRoom[i] != -1)
        v[prevRoom[i]].push_back(i);
    }
    return static_cast<int>(dfs(0, v).second);
  }
};