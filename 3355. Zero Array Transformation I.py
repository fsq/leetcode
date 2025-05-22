class Solution:
    def isZeroArray(self, a: List[int], queries: List[List[int]]) -> bool:
        s = [0] * (len(a) + 1)
        for l, r in queries:
            s[l] += 1
            s[r+1] -= 1
        
        s = list(accumulate(s))
        return all([pref >= x for pref, x in zip(s, a)])
        