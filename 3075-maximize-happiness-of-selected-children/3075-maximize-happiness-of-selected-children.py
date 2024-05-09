class Solution:
    def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
        happiness.sort(reverse=True)
        n = len(happiness) -1
        ans = 0
        i=0
        while(k):
            happiness[i] = max(happiness[i] - i, 0)
            ans = ans + happiness[i]
            i += 1
            k -= 1 
            
        return ans
                