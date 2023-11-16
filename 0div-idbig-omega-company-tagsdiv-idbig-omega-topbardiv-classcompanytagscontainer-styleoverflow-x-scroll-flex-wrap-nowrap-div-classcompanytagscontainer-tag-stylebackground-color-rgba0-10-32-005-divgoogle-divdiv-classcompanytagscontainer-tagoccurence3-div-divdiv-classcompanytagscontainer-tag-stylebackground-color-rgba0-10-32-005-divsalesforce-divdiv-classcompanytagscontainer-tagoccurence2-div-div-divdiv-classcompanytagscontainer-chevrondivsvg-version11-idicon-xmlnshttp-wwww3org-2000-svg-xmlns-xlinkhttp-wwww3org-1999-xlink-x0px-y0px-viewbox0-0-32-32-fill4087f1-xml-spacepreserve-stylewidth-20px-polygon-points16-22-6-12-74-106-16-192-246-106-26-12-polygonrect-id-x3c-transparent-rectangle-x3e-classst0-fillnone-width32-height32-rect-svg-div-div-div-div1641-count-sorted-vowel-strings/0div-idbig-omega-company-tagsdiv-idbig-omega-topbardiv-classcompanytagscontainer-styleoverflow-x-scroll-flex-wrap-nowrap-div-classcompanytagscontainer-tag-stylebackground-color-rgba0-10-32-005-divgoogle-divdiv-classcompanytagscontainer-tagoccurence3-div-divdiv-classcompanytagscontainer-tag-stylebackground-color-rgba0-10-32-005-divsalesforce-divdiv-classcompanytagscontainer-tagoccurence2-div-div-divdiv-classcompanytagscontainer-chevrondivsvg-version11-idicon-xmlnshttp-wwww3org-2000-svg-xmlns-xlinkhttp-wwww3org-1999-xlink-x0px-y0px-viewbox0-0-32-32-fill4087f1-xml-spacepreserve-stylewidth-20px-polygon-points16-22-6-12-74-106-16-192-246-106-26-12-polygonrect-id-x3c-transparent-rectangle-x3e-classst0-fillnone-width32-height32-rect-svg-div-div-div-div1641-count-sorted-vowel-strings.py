class Solution:
    def countVowelStrings(self, n: int) -> int:
        def count(n, vow):
            if vow == 0:
                dp[n][vow] = 0
            if n == 0:
                dp[n][vow] = 1
            if dp[n][vow] != -1:
                return dp[n][vow]
            dp[n][vow] = count(n-1, vow) + count(n, vow-1)
            return dp[n][vow]
        dp = [[-1]*6 for i in range(n+1)]
        return count(n, 5)
            
        