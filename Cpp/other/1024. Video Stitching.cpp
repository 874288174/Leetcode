class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        int n = clips.size();
        vector<int> dp(T+1, n+1);
        dp[0] = 0;
        sort(clips.begin(), clips.end());
        int farest = 0;
        for (auto &v : clips) {
            if (v[0] > farest) break;
            for (int k = v[0]; k <= min(T, v[1]); ++k) {
                dp[k] = min(dp[k], dp[v[0]] + 1);
            }
            farest = max(farest, v[1]);
        }
        return farest < T ? -1 : dp[T];
    }
};