func longestValidParentheses(s string) int {
	dp := make([]int, len(s))
	res := 0
	for i := 1; i < len(s); i++ {
		if s[i] == ')' {
			if s[i-1] == '(' {
				if i-2 >= 0 {
					dp[i] = 2 + dp[i-2]
				} else {
					dp[i] = 2
				}
			} else if i-1-dp[i-1] >= 0 && s[i-1-dp[i-1]] == '(' {
				if i-1-dp[i-1]-1 >= 0 {
					dp[i] = dp[i-1] + 2 + dp[i-1-dp[i-1]-1]
				} else {
					dp[i] = dp[i-1] + 2
				}
			}
		}
		if dp[i] > res {
			res = dp[i]
		}
	}
	return res
}