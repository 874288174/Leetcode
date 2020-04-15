class Solution {
public:
    Solution(vector<int> nums) : arr(nums), nums(nums) {};
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return arr = nums;    
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //random_shuffle(arr.begin(), arr.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            swap(arr[i], arr[rand() % (i+1)]);
        }
        return arr;    
    }
private:
    vector<int> arr, nums;
};
