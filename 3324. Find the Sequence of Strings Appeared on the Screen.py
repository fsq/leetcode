class Solution:
    def stringSequence(self, s: str) -> List[str]:
        ans = []
        for i in range(len(s)):
            for c in range(ord('a'), ord(s[i])+1):
                ans.append(s[:i] + chr(c))
        return ans