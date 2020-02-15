class Solution {
public:
    int superEggDrop(int K, int N) {
       vector<vector<int>> dp(K + 1, vector<int> (N+1, 0));
# 当前有 k 个鸡蛋，可以尝试扔 m 次鸡蛋
# 这个状态下，最坏情况下最多能确切测试一栋 n 层的楼
       int m = 0;
       while (dp[K][m] < N) {
          m++;
          for (int k = 1; k <= K; k++)
          dp[k][m] = dp[k][m - 1] + dp[k - 1][m - 1] + 1;
       }
       return m;
   }
};
/*
class Solution {
public:
    int superEggDrop(int K, int N) {
        if (K == 1) return N;
        if (N <= 1) return 1;
        if (dp.count(make_pair(K, N))) return dp[make_pair(K, N)];
        int ret = INT_MAX;
        //for (int i = 1; i <= N; ++i) {
        //  ret = min(ret, 1 + max(superEggDrop(K-1, i-1), superEggDrop(K, N-i)));
        //}
        int left = 0, right = N;
        while (left <= right) {
            int mid = left + (right-left) / 2;
            int broken = superEggDrop(K-1, mid-1);
            int not_broken = superEggDrop(K, N-mid);
            if (broken > not_broken) {
                right = mid-1;
                ret = min(ret, broken+1);
            }
            else {
                left = mid+1;
                ret = min(ret, not_broken+1);
            }
        }
        return dp[make_pair(K, N)] = ret;
    }
private:
    map<pair<int, int>, int> dp;
};
*/