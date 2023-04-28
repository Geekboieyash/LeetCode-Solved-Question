class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        gmax, gmin = nums[0], nums[0]
        curmax, curmin = 0,0
        total = 0
        
        for n in nums:
            curmax = max(curmax+n, n)
            curmin = min(curmin+n, n)
            total += n
            gmax = max(gmax, curmax)
            gmin = min(gmin,curmin)
            
        return max(gmax, total-gmin) if gmax>0 else gmax