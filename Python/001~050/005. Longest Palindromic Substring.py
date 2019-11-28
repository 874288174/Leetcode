class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s: return ""
        n, start, maxlen = len(s), 0, 1
        dp = [[False]*n for _ in range(n)]
        for i in range(n):
            dp[i][i] = True
            if i+1 < n and s[i] == s[i+1]:
                dp[i][i+1], maxlen, start = True, 2, i
                
        for k in range(2, n):
            for i in range(0, n-k):
                Flag = False
                if s[i] == s[k+i] and dp[i+1][i+k-1]: 
                    dp[i][i+k] = Flag = True
                if Flag:
                    start, maxlen = i, k+1;
                    
        return s[start: maxlen+start] 


'''
class Solution:
    def longestPalindrome(self, s: str) -> str:
        t = '#' + '#'.join(s) + '#'
        n = len(t)
        f = [0] * n
        res, maxLen, maxRight, pos = "", 0, 0, 0
        for i in range(n):
            f[i] = min(maxRight-i, f[pos*2-i]) if i < maxRight else 1
            while i >= f[i] and i+f[i] < n and t[i+f[i]] == t[i-f[i]]:
                f[i] += 1
            if i + f[i]-1 > maxRight:
                maxRight = i + f[i] - 1
                pos = i
            if f[i] > maxLen:
                maxLen = f[i]
                res = s[(i + 1 - maxLen)//2: (i - 1 + maxLen)//2]
        return res
'''