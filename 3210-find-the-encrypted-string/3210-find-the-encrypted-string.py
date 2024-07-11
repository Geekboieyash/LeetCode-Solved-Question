class Solution:
    def getEncryptedString(self, s: str, k: int) -> str:
        n = len(s)
        r = ''
        for i in range(n):
            r += s[(i + k) % n]
        return r