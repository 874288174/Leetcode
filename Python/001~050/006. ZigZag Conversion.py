class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows == 1: return s
        n, res = len(s), ''
        for i in range(numRows):
            for j in range(i, n, 2*numRows-2):
                res += s[j]
                if i == 0 or i == numRows-1: continue
                if j+2*(numRows-i-1) < n: res += s[j+2*(numRows-i-1)]
        return res