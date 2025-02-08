class Solution:
    def maxHeightOfTriangle(self, a: int, b: int) -> int:
        def f(a, b)->int:
            d = 1
            while a >= d:
                a -= d
                a, b = b, a
                d += 1
            return d - 1

        return max(f(a, b), f(b, a))
        