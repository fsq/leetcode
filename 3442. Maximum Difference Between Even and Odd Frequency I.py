class Solution:
    def maxDifference(self, s: str) -> int:
        c = Counter(list(s))
        f1 = max([x for x in c.values() if x & 1]) or 0
        f2 = min([x for x in c.values() if not (x & 1)]) or 0
        return f1 - f2
