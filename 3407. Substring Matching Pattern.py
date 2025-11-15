class Solution:
    def hasMatch(self, s: str, p: str) -> bool:
        a, b = p.split('*')
        x, y = s.find(a), s.rfind(b)
        if x == -1 or y == -1:
            return False
        return x + len(a) <= y
