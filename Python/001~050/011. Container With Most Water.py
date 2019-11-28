class Solution:
    def maxArea(self, height: List[int]) -> int:
        res, L, R = 0, 0, len(height)-1
        while L < R:
            res = max(res, (R-L)*min(height[L], height[R]))
            if height[L] > height[R]: R -= 1
            else: L += 1
        return res