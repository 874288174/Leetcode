class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n-3; ++i) {
            if (i > 0 && nums[i] == nums[i-1]) continue;
            for (int j = i+1; j < n-2; ++j) {
                if (j > i+1 && nums[j] == nums[j-1]) continue;
                int left = j+1, right = n-1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left+1]) ++left;
                        while (left < right && nums[right] == nums[right-1]) --right;
                        ++left; --right;
                    }
                    else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return res;
    }
};



/////////////////////好O（n^2） 坏O（n^4）//////////////////////////////



class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        unordered_map<int, vector<pair<int,int>>> My_map;
        int n = nums.size();
        if (n < 4) return res;
        sort(nums.begin(), nums.end());
        for (auto i = 0; i < n; i++){
            for (int j = i+1; j < n; j++)
                My_map[nums[i]+nums[j]].emplace_back(i, j);
        }
        for (auto &i : My_map) if (My_map.count(target-i.first)){
            auto j = My_map.find(target-i.first);
            for(auto &[a, b] : i.second){
                for(auto &[c, d] : j->second) {
                    if (b>= c) continue;
                    res.push_back({nums[a],nums[b],nums[c],nums[d]});
                }
            }
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return  res;
    }
};
