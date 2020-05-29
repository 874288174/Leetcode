class Solution:
    def intToRoman(self, num: int) -> str:
        values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1] 
        numerals = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"] 
        res = ""
        for n, v in zip(numerals, values):
            res += (num // v) * n     
            num %= v 
        return res
    
'''
class Solution:
    def intToRoman(self, num: int) -> str:
        d = {1000:'M', 900:'CM', 500:'D', 400:'CD',
             100:'C', 90:'XC', 50:'L', 40:'XL',
             10:'X', 9:'IX', 5:'V', 4:'IV', 1:'I'}
    
        res = ''
        for k in d:
            res += (num // k) * d[k]
            num %= k
        return res
'''