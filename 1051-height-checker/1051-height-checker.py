class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        a = sorted(heights)
        cnt = 0
        for i in range(len(heights)):
            if heights[i] != a[i]:
                cnt+=1
        return cnt