func searchRange(nums []int, target int) []int {
	leftmost := sort.Search(len(nums), func(i int) bool { return nums[i] >= target })
	if leftmost == len(nums) || nums[leftmost] != target {
		return []int{-1, -1}
	}
	rightmost := sort.SearchInts(nums, target+1) - 1
	return []int{leftmost, rightmost}
}