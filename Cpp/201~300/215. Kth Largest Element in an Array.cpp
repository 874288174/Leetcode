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
    int partition(vector<int>& nums, int left, int right) {
        int pivot = nums[left], l = left + 1, r = right;
        while (l <= r) {
            while (l <= r && nums[l] >= pivot)  l++;
            while (l <= r && nums[r] <= pivot)  r--;
            if (l <= r && nums[l] < pivot && nums[r] > pivot) {
                swap(nums[l++], nums[r--]);
            }
        }
        swap(nums[left], nums[r]); 
        // swap(nums[left], nums[l];会在nums = [1] 时出错 
        return r;
    }
};