class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        n, m = len(s), len(p)
        dp = [[False] * (n+1) for _ in range(m+1)]
        dp[0][0] = True
        for i in range(1, m):
             dp[i+1][0] = dp[i-1][0] and p[i] == '*'
                
        for i in range(m):
            for j in range(n):
                if p[i] == '*':
                    dp[i+1][j+1] = dp[i-1][j+1] or dp[i][j+1]
                    if p[i-1] == s[j] or p[i-1] == '.':
                        dp[i+1][j+1] |= dp[i+1][j]
                else:
                    dp[i+1][j+1] = dp[i][j] and (p[i] == s[j] or p[i] == '.')
        return dp[-1][-1]
                
            