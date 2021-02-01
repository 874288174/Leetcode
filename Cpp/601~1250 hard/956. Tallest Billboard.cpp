//O(N * Sum)
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int S = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(2, vector<int> (S + 1, INT_MIN));
        //dp[i]为高度相差i的两杆和, 转移方程由接到 短的、长的、不接 得到
        dp[0][0] = 0;
        int p = 0;
        for (auto rod : rods) {
            auto &pre = dp[p], &cur = dp[p^1];
            for (int i = 0; i <= S; ++i) {
                cur[i] = pre[i]; //不接
                cur[i] = max(cur[i], pre[abs(i-rod)] + rod);
                if (i + rod <= S)
                    cur[i] = max(cur[i], pre[i+rod] + rod);
            }
            p ^= 1;
        }
        return dp[p][0] / 2;
    }
};








//O(2^N * N)
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        unordered_map<int, int> mp{{0, 0}};
        //key 差值  value 长度和
        for(auto &rod :rods) {
            unordered_map<int, int> tmp(mp);
            for(auto &[sub, len] : tmp) {
                mp[sub + rod] = max(mp[sub + rod], len + rod);
                mp[abs(sub - rod)] = max(mp[abs(sub - rod)], len + rod);
            }
        }
        return mp[0] / 2;
    }
};