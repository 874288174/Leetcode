class Solution {
public:
    Solution(vector<int> nums) : arr(nums), nums(nums) {};
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr = nums;    
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int j = rand() % (i + 1);
            swap(arr[i], arr[j]);
        }
        return arr;    
    }
private:
    vector<int> arr, nums;
};