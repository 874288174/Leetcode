class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
                while (nums[j] < nums[i]) j--;
                swap(nums[i], nums[j]);
                int l = i+1, r = n-1;
                while(l < r)  swap(nums[l++], nums[r--]); 
                return true;
            } 
        }
        return false;
    } 
};


////////////////////////////////////DFS/////////////////////////////////


class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
	    vector<vector<int>> res;
	    dfs(num, 0, res);
	    return res;
    }
    
private:
	void dfs(vector<int> &num, int cur, vector<vector<int>> &res)	{
		if (cur >= num.size()) {
		    res.push_back(num);
		    return;
		}
		for (int i = cur; i < num.size(); i++) {
		    swap(num[cur], num[i]);
		    dfs(num, cur + 1, res);
		    swap(num[cur], num[i]);
		}
    }
};