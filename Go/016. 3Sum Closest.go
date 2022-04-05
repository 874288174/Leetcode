func threeSumClosest(nums []int, target int) int {
	ans := math.MaxInt32
	sort.Ints(nums)
	for i, _ := range nums {
		j, k := i+1, len(nums)-1
		for j < k {
			sum := nums[i] + nums[j] + nums[k] - target
			if abs(ans) > abs(sum) {
				ans = sum
			}

			if sum == 0 {
				return target
			} else if sum < 0 {
				j++
			} else {
				k--
			}
		}
	}
	return ans + target
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}