class Solution:
    def maximumLength(self, a: List[int], k: int) -> int:
        a = list(map(lambda x: x%k, a))
        n = len(a)
        ans = 0
        for r in range(k):
            f = [0 for i in range(k)]
            for i, x in enumerate(a):
                # (x+y) = r
                y = (r+k-x) % k
                f[x] = max(f[x], f[y] + 1)
                ans = max(ans, f[x])

        return ans
