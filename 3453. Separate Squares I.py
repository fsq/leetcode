class Solution:
    def separateSquares(self, a: List[List[int]]) -> float:
        l = 0
        r = max(a, key=lambda s: s[1]+s[2])
        r = r[1] + r[2]

        def gap(m):
            g = 0
            for (x, y, l) in a:
                g += (l*min(l, max(0, m-y))) - (l*min(l, max(0, y+l-m)))
            return g


        while r-l >= 10e-6:
            m = (l + r) / 2
            if gap(m) >= 0:
                r = m
            else:
                l = m
        return (l+r) / 2
