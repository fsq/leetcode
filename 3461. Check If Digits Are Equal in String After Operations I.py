class Solution:
    def hasSameDigits(self, ss: str) -> bool:
        s = list(ss)
        while len(s) > 2:
            s = [str((int(s[i])+int(s[i+1])) % 10) for i in range(0, len(s)-1)]
        return s[0] == s[1]