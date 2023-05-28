class Solution:
    def reverseWords(self, s: str) -> str:
        result = []
        temp = ""
        for i in range(len(s)-1,-1,-1 ):
            if s[i] == " ":
                if temp:
                    result.append(temp[::-1])
                    temp = ""
                continue
            temp += s[i]
        if temp: result.append(temp[::-1])
        return " ".join(result)
            
            