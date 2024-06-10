class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return sum( v!= u for v,u in zip(heights, sorted(heights)))