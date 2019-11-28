class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans, minn = numeric_limits<int>::max();
        for (auto i = nums.begin(); i != nums.end() - 2; i++){
            auto j = i + 1, k = nums.end() - 1;
            while (j < k){
                int sum = *i + *j + *k;
                if (minn > abs(sum - target)) {
                    minn = abs(sum - target);
                    ans = sum;
                }
                if (sum < target)        j++;
                else if (sum > target)   k--;
                else return target;
            }
        }
        return ans;
    }
};