class Solution:
    def subarraysDivByK(self, nums: List[int], k: int) -> int:
        count = 0
        sum = 0
        mp = {0: 1}
        for n in nums:
            sum += n
            mod = sum%k
            if mod < 0:
                mod += k
            if mod in mp:
                count += mp[mod]
                mp[mod] += 1
            else:
                mp[mod] = 1
        return count