class Solution {
public:
    int findRotateSteps(string ring, string key) {
        unordered_map<char, vector<int>> mp;
        int n = ring.size();
        for (int i = 0; i < n; ++i) mp[ring[i]].push_back(i);
        vector<vector<pair<int, int>>> dp(2);
        dp[0].push_back({0, 0});
        int k = 0;
        for (auto c : key) {
            vector<pair<int, int>> &cur = dp[k^1], &pre = dp[k];
            cur.clear();
            for (auto pos : mp[c]) {
                int step = INT_MAX;
                for (auto &pii : pre) {
                   step = min(step, pii.second + dist(pii.first, pos, n));
                }
                cur.push_back({pos, step});
            }
            k ^= 1;
        }
        int res = INT_MAX;
        for (auto &pii : dp[k]) {
            res = min(res, pii.second); 
        }
        return res + key.size();
    }
private:
    int dist(int i, int j, int n) {
        int t = (i-j+n) % n;
        return min(t, n-t);
    }
};