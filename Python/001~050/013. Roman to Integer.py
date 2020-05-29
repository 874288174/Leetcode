class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        res = d[s[-1]]
        for k in range(len(s)-1):
            if d[s[k]] < d[s[k+1]]: res -= d[s[k]]
            else: res += d[s[k]]
        return res