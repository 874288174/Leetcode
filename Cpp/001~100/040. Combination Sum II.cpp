class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> t;
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, 0, target, t);
        return res;
    }
    
    bool dfs(vector<int>& v, int cur, int sum, int target, vector<int> &t) {
        if (sum > target) return false;
        else if (sum == target) {
            res.push_back(t);
            return false;
        }
        else for(auto i = cur; i < v.size(); i++) {
            if(i != cur && v[i] == v[i-1]) continue;
            t.push_back(v[i]); 
            if( !dfs(v, i+1, sum+v[i], target, t) ){
                t.pop_back();
                break;
            }
            t.pop_back();
        }
        return true;
    }
};