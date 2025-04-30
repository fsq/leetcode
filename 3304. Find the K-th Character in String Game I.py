class Solution:
    def kthCharacter(self, k: int) -> str:
        s = "a"
        while len(s) < k:
            s = s + ''.join([chr((ord(c)-ord('a')+1) % 26+ord('a')) for c in s])
        return s[k-1]