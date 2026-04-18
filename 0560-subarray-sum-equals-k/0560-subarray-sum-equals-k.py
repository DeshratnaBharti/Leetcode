from collections import defaultdict
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        ans =0
        sum =0
        dicti = defaultdict(int)
        dicti[0] =1
        for num in nums:
            sum = sum + num
            if(sum-k) in dicti:
                ans += dicti[sum-k]
            dicti[sum] +=1
        return ans