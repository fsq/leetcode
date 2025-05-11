class Solution:
    def isBalanced(self, s: str) -> bool:
        a = [0, 0]
        for i in range(len(s)):
            a[i % 2] += ord(s[i]) - ord('0')
        return a[0] == a[1]