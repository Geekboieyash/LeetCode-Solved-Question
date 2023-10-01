class Solution:
    def reverseWords(self, s: str) -> str:
        s = list(s)
        n = len(s)
        start = 0

        for i in range(n + 1):
            if i == n or s[i] == ' ':
                self.reverseWord(s, start, i - 1)
                start = i + 1

        return ''.join(s)

    def reverseWord(self, s, left, right):
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1
        