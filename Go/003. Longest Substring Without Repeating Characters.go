func lengthOfLongestSubstring(str string) int {
	mp, res, left := make(map[rune]int), 0, -1
	for idx, c := range str {
        if _, ok := mp[c]; ok && mp[c] >= left {
			left = mp[c]
		}
        if idx-left > res {
            res = idx - left
        }
		mp[c] = idx
	}
	return res
}