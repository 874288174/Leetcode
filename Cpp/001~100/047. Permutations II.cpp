class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int> >res;
        do{
            res.push_back(nums);
        }while( Next_Permutation(nums) );
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
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> out;
        vector<int> visited(num.size(), 0);
        sort(num.begin(), num.end());
        permuteUniqueDFS(num, 0, visited, out, res);
        return res;
    }
    void permuteUniqueDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
        if (level == num.size()) res.push_back(out);
        else for (int i = 0; i < num.size(); ++i) {
            if (!visited[i]) {
                if (i > 0 && num[i] == num[i - 1] && !visited[i - 1]) continue;
                visited[i] = 1;
                out.push_back(num[i]);
                permuteUniqueDFS(num, level + 1, visited, out, res);
                out.pop_back();
                visited[i] = 0;
            }
        }
    }
};