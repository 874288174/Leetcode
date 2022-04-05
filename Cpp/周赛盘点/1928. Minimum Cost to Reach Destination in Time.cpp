// f[t][i] 表示使用恰好t分钟到达城市i需要的最少通行费总和
class Solution {
private:
  static constexpr int INFTY = 1e9;

public:
  int minCost(int maxTime, vector<vector<int>> &edges,
              vector<int> &passingFees) {
    int n = passingFees.size();
    vector<vector<int>> f(maxTime + 1, vector<int>(n, INFTY));
    f[0][0] = passingFees[0];
    for (int t = 1; t <= maxTime; ++t) {
      for (const auto &edge : edges) {
        int i = edge[0], j = edge[1], cost = edge[2];
        if (cost <= t) {
          f[t][i] = min(f[t][i], f[t - cost][j] + passingFees[i]);
          f[t][j] = min(f[t][j], f[t - cost][i] + passingFees[j]);
        }
      }
    }

    int res = 1e9;
    for (int t = 1; t <= maxTime; ++t) {
      res = min(res, f[t][n - 1]);
    }
    return res >= 1e9 ? -1 : res;
  }
};