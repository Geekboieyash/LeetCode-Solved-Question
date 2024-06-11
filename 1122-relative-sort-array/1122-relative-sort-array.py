class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        freq = {}
        for num in arr1:
            if num in freq:
                freq[num] += 1
            else:
                freq[num] = 1
        result = []
        for num in arr2:
            if num in freq:
                result.extend([num]*freq[num])
                del freq[num]
        for num in sorted(freq.keys()):
             result.extend([num] * freq[num])
        return result
        