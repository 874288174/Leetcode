//O(nlogn)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(),nums.end());
	    vector<int> res(nums);
	    int n = nums.size();
	    int end0 = (n+1)/2 - 1, end1 = n - 1;
	    for (int i = 0; i < n; i++) {
	    	nums[i] = i % 2 == 0 ? res[end0--]: res[end1--] ;
    	}
    }
};



//O(n)
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size(), mid = (n + 1) / 2 - 1;
        nth_element(nums.begin(), nums.begin() + mid, nums.end());
        threeWayPartition(nums, nums[mid]);
        vector<int> res(nums);
        int end0 = (n + 1) / 2 - 1, end1 = n-1;
        for (int i = 0; i < n; ++i) {
            nums[i] = i % 2 == 0 ? res[end0--] : res[end1--];
        }
    }
    
    void threeWayPartition(vector<int> &nums, int val) {
        int i = 0, j = 0, k = nums.size()-1;
        while (j <= k){
            if (nums[j] < val)
                swap(nums[i++], nums[j++]);
            else if (nums[j] > val)
                swap(nums[j], nums[k--]);
            else ++j;
        }
    }
};