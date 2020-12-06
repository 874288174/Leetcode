class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> mp;
        for (int x: nums) ++mp[x];
        
        vector<int> cnt;
        for (auto& i: mp) {
            cnt.emplace_back(i.second);
        }
        
        int n = cnt.size(), m = quantity.size();
        vector<int> sum(1 << m, 0);
        for (int i = 1; i < (1 << m); i++) {
            for (int j = 0; j < m; j++) {
                if (i & (1 << j)) {
                    int left = i - (1 << j);
                    sum[i] = sum[left] + quantity[j];
                    break;
                }
            }
        }
        
        vector<vector<bool>> dp(2, vector<bool>(1 << m, false));
        dp[0][0] = true;
        int k = 0;

        for (int i = 0; i < n; i++) {
            auto &pre = dp[k], &cur = dp[k^1];
            for (int j = 0; j < (1 << m); j++) {
                cur[j] = j == 0 ? true : false;
                if (i > 0 && pre[j]) cur[j] = true;
                else for (int s = j; s != 0; s = ((s - 1) & j)) {
                    int prev = j - s;
                    // cnt[0..i-1] 能否满足子集 prev
                    bool last = (i == 0) ? (prev == 0) : pre[prev]; 
                    // cnt[i] 能否满足子集 s
                    bool need = sum[s] <= cnt[i]; 
                    if (last && need) {
                        cur[j] = true;
                        break;
                    }
                }
            }
            k ^= 1;
        }
        return dp[k].back();
    }
};