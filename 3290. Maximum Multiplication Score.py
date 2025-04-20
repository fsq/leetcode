class Solution:
    def maxScore(self, a: List[int], b: List[int]) -> int:
        f = [-inf] * 4
        for x in b:
            for i in reversed(range(1, 4)):
                f[i] = max(f[i], f[i-1] + x*a[i])
            f[0] = max(f[0], a[0] * x)
        return f[3]