class Solution:
    def answerString(self, s: str, nf: int) -> str:
        if nf == 1:
            return s
        l = len(s) - nf + 1
        ans = ""
        mc = max(s)
        return max([s[i:i+l] for i,c in enumerate(s) if c == mc])
