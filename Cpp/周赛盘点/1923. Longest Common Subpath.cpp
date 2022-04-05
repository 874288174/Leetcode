class Solution {
public:
  using ul = unsigned long;
  static constexpr ul pa = 97, ma = 1e9 + 7;
  static constexpr ul pb = 23, mb = 1e9 + 13;

  vector<ul> pPowerA, pPowerB;

  vector<vector<ul>> RollsA, RollsB;

  vector<ul> RollingHash(const vector<int> &s, ul p, ul m) {
    vector<ul> hashMap(s.size() + 1);
    for (int i = 1; i < hashMap.size(); ++i) {
      hashMap[i] = (hashMap[i - 1] * p + s[i - 1]) % m;
    }
    return hashMap;
  }

  ul getHashCode(int i, int j, const vector<ul> &hashMap,
                 const vector<ul> &pPower, ul p, ul m) {
    if (i == 0)
      return hashMap[j];
    return (hashMap[j] + m - (hashMap[i] * pPower[j - i]) % m) % m;
  }

  int longestCommonSubpath(int n, vector<vector<int>> &paths) {
    pPowerA.resize(100005, 1);
    pPowerB.resize(100005, 1);

    for (int i = 1; i < 100005; ++i) {
      pPowerA[i] = (pPowerA[i - 1] * pa) % ma;
      pPowerB[i] = (pPowerB[i - 1] * pb) % mb;
    }
    for (auto &s : paths) {
      RollsA.push_back(RollingHash(s, pa, ma));
      RollsB.push_back(RollingHash(s, pb, mb));
    }

    int l = 0, r = INT_MAX;
    for (auto &p : paths)
      r = min((int)p.size(), r);

    while (l < r) {
      if (l == r - 1) {
        if (check(r))
          return r;
        else if (check(l))
          return l;
      }

      int mid = l + (r - l) / 2;

      if (check(mid))
        l = mid;
      else
        r = mid - 1;
    }
    return l;
  }

  bool check(int len) {
    set<pair<ul, ul>> sta;
    for (int i = 0; i < RollsA.size(); ++i) {
      int n = RollsA[i].size();
      set<pair<ul, ul>> stb;
      for (int j = 0, k = len; k < n; ++j, ++k) {
        ul p = getHashCode(j, k, RollsA[i], pPowerA, pa, ma);
        ul q = getHashCode(j, k, RollsB[i], pPowerB, pb, mb);

        if (i == 0)
          sta.insert(pair<ul, ul>(p, q));
        else if (sta.count(pair<ul, ul>(p, q))) {
          stb.insert(pair<ul, ul>(p, q));
        }
      }

      if (i != 0) {
        sta = std::move(stb);
        if (sta.empty())
          return false;
      }
    }

    return true;
  }
};