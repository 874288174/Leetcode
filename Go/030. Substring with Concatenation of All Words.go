func findSubstring(s string, words []string) []int {
	var res []int
	if len(words) < 1 {
		return res
	}

	slen, wlen := len(s), len(words)
	k := len(words[0])
	if slen < k*wlen {
		return []int{}
	}

	var mp = make(map[string]int)
	for _, w := range words {
		mp[w]++
	}

	for i := 0; i < k; i++ {
		var count int
		var countermp = make(map[string]int)

		for l, r := i, i; r <= slen-k; r = r + k {
			word := s[r : r+k]
			if num, found := mp[word]; found {
				for countermp[word] >= num {
					countermp[s[l:l+k]]--
					count--
					l += k
				}
				countermp[word]++
				count++
			} else {
				for l < r {
					countermp[s[l:l+k]]--
					count--
					l += k
				}
				l += k
			}
			if count == wlen {
				res = append(res, l)
			}
		}
	}
	return res
}