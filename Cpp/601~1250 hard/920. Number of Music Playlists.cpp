//dp(i,j) 前i首歌有j首不同的歌
class Solution {
public:
    using ll = long long;
    const static ll mod = 1e9 + 7;
    
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<ll>> dp(L+1, vector<ll> (N+1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= L; ++i) {
            for (int j = N; j > 0; --j) {
                dp[i][j] += dp[i-1][j-1]*(N+1-j);
                dp[i][j] += dp[i-1][j] * max(0, j-K);
                dp[i][j] %= mod;
            }
        }
        return static_cast<int> (dp[L][N]);
    }
};
