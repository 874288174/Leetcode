class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i, v in enumerate(nums): 
            if v in m:
                return [m[v], i]
            m[target-v] = i
        return -1, -1
		
'''
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i in range(len(num)):
            if num[i] in m: return m[num[i]], i
            m[target - num[i]] = i  
        return -1, -1
'''