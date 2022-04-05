class Solution {
public:
    int n;
    vector<pair<int, int>> pos[51];
    
    vector<int> getCoprimes(vector<int>& nums, vector<vector<int>>& edges) {
        n = nums.size();
        vector<int> res(n, -1);
        vector<vector<int>> child(n);
        
        for (auto &e : edges) {
            child[e[0]].push_back(e[1]);
            child[e[1]].push_back(e[0]);
        }
        dfs(0, -1, 0, nums, child, res);
        return res;
    }
    
    void dfs(int i, int fa, int cnt, vector<int>& nums, vector<vector<int>>& child, vector<int> &res) {
        int p = -1, tmp = -1;
        for (int k = 1; k <= 50; ++k) {
            if (!pos[k].empty() && __gcd(nums[i], k) == 1) {
                if (pos[k].back().first > p) {
                    p = pos[k].back().first;
                    tmp = pos[k].back().second;
                }
            }
        }
        res[i] = tmp;
        
        pos[nums[i]].emplace_back(cnt, i);
        for (auto j : child[i]) {
            if (j != fa) {
                dfs(j, i, cnt+1, nums, child, res);
            }
        }
        pos[nums[i]].pop_back();
    }
};
