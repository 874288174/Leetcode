func longestCommonPrefix(strs []string) string {
	if len(strs) == 0 {
		return ""
	}

	var res strings.Builder
	for i := 0; ; i++ {
		for _, str := range strs {
			if i == len(str) || strs[0][i] != str[i] {
				return res.String()
			}
		}
		res.WriteByte(strs[0][i])
	}
}