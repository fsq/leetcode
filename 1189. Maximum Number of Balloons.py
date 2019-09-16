class Solution:
    def maxNumberOfBalloons(self, s: str) -> int:
        d = collections.Counter(s)
        return min(min([d.get(c, 0) for c in "ban"]), min([d.get(c, 0)//2 for c in "lo"]))
        
        