class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1.0;
        vector<double> dp(N + 1);
        dp[0] = 1.0;
        double Wsum = 1.0, res = 0.0;
        //Wsum = dp[i-1] + dp[i-2] + dp[i-W]
        for (int i = 1; i <= N; ++i) {
            dp[i] = Wsum / W;
            if (i - W >= 0) Wsum -= dp[i - W];
            if (i >= K) res += dp[i];
            else Wsum += dp[i]; 
        }
        return res;
    }
};


/////////TL////////////////
class Solution {
public:
    double new21Game(int N, int K, int W) {
        if (K == 0 || N >= K + W) return 1.0;
        //dp(i) = sum(dp(t) / W)
        vector<double> dp(N+1, 0);
        dp[0] = 1;
        double res = 0;
        for (int i = 1; i <= N; ++i) { 
            for (int t = max(0, i-W); t < i; ++t) {
                if (t >= K) break;
                dp[i] += dp[t] / W;
            }
            if (i >= K) res += dp[i];
        }
        return res;
    }
};