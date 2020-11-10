class Solution {
	int get_index(vector<int>& nums, int k, int N) {
		return (k + nums[k] + N) % N;
	}
public:
	bool circularArrayLoop(vector<int>& nums) {
		int N = nums.size();
        for (auto &i : nums) i %= N;

		for (int i = 0; i < N; i++) {
			if (nums[i] == 0) continue;
			long sign = nums[i] > 0 ? 1 : -1;
			int slow = i, fast = i;
			while (1) {
				fast = get_index(nums, fast, N);
				if (nums[fast] * sign <= 0) break;
				fast = get_index(nums, fast, N);
				if (nums[fast] * sign <= 0) break;
				slow = get_index(nums, slow, N);
				if (slow == fast) return true;
			}
			slow = i;
			while (slow != fast) {
				int l = slow;
				slow = get_index(nums, slow, N);
				nums[l] = 0;
			}
		}
		return false;
	}
};