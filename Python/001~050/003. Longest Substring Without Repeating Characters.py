class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if not s: return 0
        left, res, m = -1, 0, [-1 for i in range(256)]
        for i, v in enumerate(s):
            left = max(left, m[ord(v)])
            res = max(res, i-left)
            m[ord(v)] = i;
        return res
        