func longestPalindrome(s string) string {
	n, res := len(s), ""
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n)
	}
	for l := 0; l < n; l++ {
		for i, j := 0, l; j < n; i, j = i+1, j+1 {
			if s[i] == s[j] {
				if j-i < 2 {
					dp[i][j] = j - i + 1
				} else if dp[i+1][j-1] != 0 {
					dp[i][j] = dp[i+1][j-1] + 2
				}
			}
			if dp[i][j] > len(res) {
				res = s[i : i+l+1]
			}
		}
	}
	return res
}