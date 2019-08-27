class Solution:
    def numSmallerByFrequency(self, q: List[str], w: List[str]) -> List[int]:
        F = lambda s: s.count(min(s))
        fw = sorted([F(s) for s in w])
        return [len(fw)-bisect.bisect_right(fw, F(s)) for s in q]
        