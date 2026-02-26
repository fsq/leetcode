class Solution:
    def maxSum(self, a: List[int], k: int, m: int) -> int:
        n = len(a)
        # f[n][k] = first n elem, total k segs
        #         = f[n-1][k], g[n][k]
        # g[n][k] = first n elem, total k segs, end with n
        #         = g[n-1][k]+a[n], f[n-m][k-1]+a[n-m+1:n]


        @functools.lru_cache(maxsize=None)
        def g(n, k):
            if k == 0:
                return 0
            if m*k > n+1:
                return -inf
            # a[n] either append to previous seg, or start a new seg
            ans = g(n-1, k) + a[n]
            if n-m+1>=0:
                ans = max(ans, f(n-m, k-1)+sum(a[n-m+1:n+1]))
            return ans

        @functools.lru_cache(maxsize=None)
        def f(n, k):
            if k == 0:
                return 0
            if m*k > n+1:
                return -inf
            return max(f(n-1, k), g(n, k))

        return f(n-1, k)
