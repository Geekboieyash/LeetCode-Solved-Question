class Solution:
    def countBits(self, n: int) -> List[int]:
        arr = []
        sum = 0
        for i in range(n+1):
            sum = bin(i).count('1')
            arr.append(sum)
        return arr
            
            