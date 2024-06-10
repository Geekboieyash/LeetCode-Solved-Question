class Solution:
    def maxEnvelopes(self, envelopes: List[List[int]]) -> int:
        envelopes.sort(key = lambda x: (x[0], -x[1]))
        arr = []
        size = 0
        for (w, h) in envelopes:
            if not arr or h > arr[-1]:
                arr.append(h)
                size += 1
            else:
                l, r = 0, size
                while l<r:
                    m = l + (r-l)//2
                    if arr[m] < h:
                        l = m+1
                    else:
                        r = m
                arr[l] = h
        return size