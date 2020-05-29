class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n, m = len(nums1), len(nums2)
        a = self.findK(nums1, 0, nums2, 0, (n+m+1)//2)
        b = self.findK(nums1, 0, nums2, 0, (n+m+2)//2) if (n+m+1)%2 else a
        return (a+b)/2
    
    def findK(self, nums1, p, nums2, q, k):
        n, m = len(nums1), len(nums2)
        if p == n: return nums2[q+k-1]
        elif q == m: return nums1[p+k-1]
        elif k == 1: return min(nums1[p], nums2[q])
        a = nums1[p+k//2-1] if p+k//2-1 < n else 2**31
        b = nums2[q+k//2-1] if q+k//2-1 < m else 2**31
        if a < b: 
            return self.findK(nums1, p+k//2, nums2, q, k-k//2)
        else:
            return self.findK(nums1, p, nums2, q+k//2, k-k//2)