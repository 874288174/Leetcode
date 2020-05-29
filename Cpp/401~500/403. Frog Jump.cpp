/*
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        unordered_set<int> s[n];
        s[0].insert(0);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (s[j].empty()) continue;
                int d = stones[i] - stones[j];
                if (d > n) continue;
                if (s[j].count(d-1) || s[j].count(d) || s[j].count(d+1) )  {  
                    s[i].insert(d);
                }
            }
        }
        return !s[n-1].empty();
    }
};
*/
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int N = stones.size();
        vector<vector<bool>> dp(N, vector<bool>(N+1, false));
        dp[0][1] = true;
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                int d = stones[i] - stones[j];
                if (d < 0 || d > N || !dp[j][d]) continue;
                dp[i][d] = true;
                if (d - 1 >= 0) dp[i][d-1] = true;
                if (d + 1 <= N) dp[i][d+1] = true;
                if (i == N-1) return true;
            }
        }
        return false;
    }
};