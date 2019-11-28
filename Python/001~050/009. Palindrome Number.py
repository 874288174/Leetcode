class Solution:
    def isPalindrome(self, x: int) -> bool:
#       return x >= 0 and str(x) == str(x)[::-1]
        if x < 0: return False
        ori_x, y = x, 0
        while x:
            y = 10*y + x%10
            x //= 10
        return ori_x == y