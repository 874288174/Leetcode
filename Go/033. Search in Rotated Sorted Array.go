func search(nums []int, target int) int {
	var lo, hi int = 0, len(nums) - 1

	for lo <= hi {
		var mid = lo + (hi-lo)/2

		if nums[mid] == target {
			return mid
		}

		if nums[lo] <= nums[mid] {
			if target >= nums[lo] && target <= nums[mid] {
				hi = mid - 1
			} else {
				lo = mid + 1
			}
		} else if nums[mid] < nums[hi] {
			if target > nums[mid] && target <= nums[hi] {
				lo = mid + 1
			} else {
				hi = mid - 1
			}
		}
	}
	return -1
}