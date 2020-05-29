class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(0, nums, v);
        return res;
    }
private:
    void dfs(int cur, vector<int> &nums, vector<int> &v) {
        if (cur == nums.size()) {
            res.push_back(v);
            return;
        }
        v.push_back(nums[cur]);
        dfs(cur+1, nums, v);
        v.pop_back();
        dfs(cur+1, nums, v);
    }
};



////////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for (int i = 0; i < (1<<n) ; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if (i & (1<<j)) v.push_back(nums[j]);
            }
            res.push_back(v);
        }
        return res;
    }
};



///////////////////////////////////////////////////////////////////////
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res{{}};
        for(auto &x : nums){
            res.reserve(res.size()*2);
            auto half = res.begin()+res.size();  // auto half = res.end();
            copy(res.begin(), res.end(), back_inserter(res));
            for_each(res.begin(), half, [&x](decltype(res[0]) &v){
               v.push_back(x);
            });
            /*int sz = res.size();
            for(int i = 0; i < sz; i++) {
                res.push_back(res[i]);
                res.back().push_back(x);
            }*/
        }
        return res;
    }
};