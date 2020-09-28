class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if (nums.size() < 3) return ans;
        sort(nums.begin(), nums.end());
        for (auto i = nums.begin(); i != nums.end()-2; i++){
            if (i > nums.begin() && *i == *(i-1)) continue;
            auto j = i + 1, k = nums.end() - 1;
            while (j < k){
                if (*i + *j + *k < 0) j++;
                else if (*i + *j + *k > 0)  k--;
                else {
                    ans.push_back({*i,*j,*k});
                    j++; k--;
                    while (j < k && *j == *(j-1)) j++;
                    while (j < k && *k == *(k+1)) k--;
                }
            }
        }
        return ans;
    }
};