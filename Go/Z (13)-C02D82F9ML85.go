func generateParenthesis(n int) []string {
	result := make([]string, 0)
	var sign []byte
	backtrack(&result, sign, 0, 0, n)
	return result
}

func backtrack(result *[]string, sign []byte, open, close, max int) {
	if len(sign) == max*2 {
		*result = append(*result, string(sign))
		return
	}
	if open < max {
		backtrack(result, append(sign, '('), open+1, close, max)
	}
	if close < open {
		backtrack(result, append(sign, ')'), open, close+1, max)
	}
}