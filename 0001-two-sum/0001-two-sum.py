class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
       n = len(nums)
       mp = {}
       for i, num in enumerate(nums):
           a = target - num
           if a in mp:
              return [i,mp[a]]
           mp[num] = i; 
       return [-1,-1]
        