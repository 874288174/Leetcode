func letterCombinations(digits string) []string {
	if len(digits) == 0 {
		return []string{}
	}

	m := [][]string{
		[]string{"0"},
		[]string{"1"},
		[]string{"a", "b", "c"},
		[]string{"d", "e", "f"},
		[]string{"g", "h", "i"},
		[]string{"j", "k", "l"},
		[]string{"m", "n", "o"},
		[]string{"p", "q", "r", "s"},
		[]string{"t", "u", "v"},
		[]string{"w", "x", "y", "z"},
	}

	res := []string{""}

	for i := 0; i < len(digits); i++ {
		digit := int(digits[i] - '0')
		var tmp []string

		for _, j := range res {
			for _, ch := range m[digit] {
				tmp = append(tmp, j+ch)
			}
		}
		res = tmp
	}
	return res
}