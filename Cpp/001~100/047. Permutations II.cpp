class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> >res;
        do{
            res.push_back(nums);
        } while(Next_Permutation(nums));
        return res;
    }
    
    bool Next_Permutation(vector<int> &nums) {
        int n = nums.size(), i, j;
        for (i = n-2, j = n-1; i >= 0; i--) { 
            if (nums[i] < nums[i+1]) {
                while (nums[j] <= nums[i]) j--;
                swap(nums[i], nums[j]);
                int l = i+1, r = n-1;
                while(l < r)  swap(nums[l++], nums[r--]); 
                return true;
            } 
        }
        return false;
    }
    
};



//////////////////////////////////////////////////////////////////////////////DFS/////////////////////////////////
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& num) {
        vector<vector<int>> res;
        dfs(num, 0, res);
        return res;
    }
    
private:
    void dfs(vector<int> &num, int cur, vector<vector<int>> &res)   {
        if (cur >= num.size()) {
            res.push_back(num);
            return;
        }
        unordered_set<int> st;
        for (int i = cur; i < num.size(); i++) {
            if (st.count(num[i])) continue;
            st.insert(num[i]);
            swap(num[cur], num[i]);
            dfs(num, cur + 1, res);
            swap(num[cur], num[i]);
        }
    }
};




///////////////////////////////注意nums为值传递//////////////////////////////
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        permute(nums, 0, res);
        return res;
    }
    void permute(vector<int> nums, int i, vector<vector<int>> &res) {
        if (i == nums.size()) res.push_back(nums);
        else for (int k = i; k < nums.size(); k++) {
            if (i != k && nums[i] == nums[k]) continue;
            swap(nums[i], nums[k]);
            permute(nums, i+1, res);
        }
    }
};
