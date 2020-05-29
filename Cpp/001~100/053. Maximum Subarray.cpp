class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0], cur = 0;
        for (auto &i : nums) {
            cur += i;
            sum = max(sum, cur);
            if (cur <= 0)  cur = 0;
        }
        return sum;
    }
};





//////////////////divide and conquer approach///////////////////////////
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return  maxSubArray(nums, 0, nums.size()-1);
    }
    
private:
    int maxSubArray(vector<int>& nums, int left, int right) {
        if (right < left) return INT_MIN;
        else if (right == left) return nums[left];
        int mid = left+(right-left)/2;
        int ret = max(maxSubArray(nums, left, mid), 
                      maxSubArray(nums, mid+1, right));
        int sum = nums[mid], temp = 0;
        for (int i = mid+1, t = 0; i <= right; i++) {
            temp = max(t += nums[i], temp);
        }
        sum += temp;
        temp = 0;
        for (int i = mid-1, t = 0; i >= left; i--) {
            temp = max(t += nums[i], temp);
        }
        return max(ret, sum += temp);
    }
};