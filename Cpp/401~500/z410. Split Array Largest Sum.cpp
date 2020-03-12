class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        for (auto i : nums) {
            left = max(left, (long long)i);
            right += i;
        }
        
        while (left < right) {
            auto mid = left + (right - left) / 2;
            if (judge(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
private:
    bool judge(const vector<int>& nums, int cnt, long long max) {
        long long sum = 0;
        for (auto i : nums) {
            if (i > max) return false;
            else if (sum + i <= max) sum += i;
            else {
                sum = i;
                if (--cnt < 0) return false;
            }
        }
        return true;
    }
};