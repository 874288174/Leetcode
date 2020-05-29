class Solution:
    def reverse(self, x: int) -> int:
        res, symbol = 0, 1
        
        if x < 0:
            symbol = -1
            x = -x

        while x:
            res = res * 10 + x % 10
            x //= 10  
            
        return 0 if res > 2**31 else res * symbol
    
'''
class Solution:
    def reverse(self, x: int) -> int:
        s = 1 if x > 0 else -1 
        r = int(str(s*x)[::-1])
        return s*r * (r < 2**31)
'''