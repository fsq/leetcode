class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        i = 0
        while i < len(word):
            cnt = 0
            j = i
            while j<len(word) and j-i<9 and word[j]==word[i]:
                j += 1
            comp += str(j-i)
            comp += word[i]
            i = j
        return comp