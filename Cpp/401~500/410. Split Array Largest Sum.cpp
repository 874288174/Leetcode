class Solution {
public:  
    using ll = long long;
    int splitArray(vector<int>& nums, int m) {
        ll left = *max_element(nums.begin(), nums.end());
        ll right = accumulate(nums.begin(), nums.end(), (ll)0);

        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (judge(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
private:
    bool judge(const vector<int>& nums, int cnt, ll max) {
        ll sum = 0;
        for (auto i : nums) {
            if (sum + i <= max) sum += i;
            else {
                sum = i;
                if (--cnt < 0) return false;
            }
        }
        return true;
    }
};