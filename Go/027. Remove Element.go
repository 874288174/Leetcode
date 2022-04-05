func removeElement(nums []int, val int) int {
	n, curIdx := len(nums), 0
	for i := 0; i < n; i++ {
		if nums[i] == val {
			continue
		}
		nums[curIdx] = nums[i]
		curIdx++
	}
	return curIdx
}