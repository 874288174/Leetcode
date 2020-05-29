class Solution {
public:
    vector<vector<int>> res;    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> v;
        dfs(0, nums, v);
        return res;
    }
private:
    void dfs(int start, vector<int> &nums, vector<int> &v) {
        res.push_back(v);
        for (int i = start; i < nums.size(); i++) {
            if (i != start && nums[i] == nums[i-1]) continue;
            v.push_back(nums[i]);
            dfs(i+1, nums, v);
            v.pop_back();
        }
    }
};


///////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> res;    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> My_map;
        for (auto &i : nums) My_map[i]++;
        vector<pair<int, int>> Nums;
        for (auto &i : My_map) Nums.push_back({i.first, i.second});
        vector<int> v;
        dfs(0, Nums, v);
        return res;
    }
private:
    void dfs(int cur, vector<pair<int, int>> &Nums, vector<int> &v) {
        if (cur == Nums.size()) {
            res.push_back(v);
            return;
        }
        int x = Nums[cur].first, n = Nums[cur].second;
        dfs(cur+1, Nums, v);
        for (int i = 0; i < n; i++) {
            v.push_back(x);
            dfs(cur+1, Nums, v);
        }
        while (n--) v.pop_back();
    }
};
