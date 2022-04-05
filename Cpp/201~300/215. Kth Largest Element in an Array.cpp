class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1;
        while (1) {
            int idx = partition(nums, left, right);
            if (idx == k-1)  break;
            if (idx < k-1) left = idx + 1;
            else right = idx - 1;
        }
        return nums[k-1];
    }
private:
//先right动， 再left动
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left, r = right;
        while (l < r) {
            while (l < r && nums[r] <= pivot)  r--;
            nums[l] = nums[r];
            while (l < r && nums[l] >= pivot)  l++;
            nums[r] = nums[l];            
        }
        nums[l] = pivot;
        return l;
    }
};