class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n = req_skills.size(), m = 1 << n;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; ++i) mp[req_skills[i]] = i;
        vector<vector<int>> dp(m);
        
        for (int p = 0; p < people.size(); ++p) {
            int mask = 0;
            for (auto &i : people[p]) mask |= (1 << mp[i]);
            for (int i = 0; i < m; ++i) {
                if ((i|mask) == i) continue;
                if (i && dp[i].empty()) continue;
                if (dp[i|mask].empty() || dp[i|mask].size() > dp[i].size() + 1) {
                    dp[i|mask] = dp[i];
                    dp[i|mask].push_back(p);
                }
            }
        }
        return dp.back();
    }                         
};