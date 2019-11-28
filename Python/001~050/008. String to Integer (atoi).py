class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()
        if not s: return 0
        res, Neg = 0, False
        if s[0] == '+' or s[0] == '-':
            Neg = (s[0] == '-')
            del s[0]
        for c in s:
            if c.isdigit() == False: break;
            res = res*10 + int(c)
        if Neg:
            return -res if res <= 2**31 else -2**31
        else:
            return res if res < 2**31 else 2**31-1