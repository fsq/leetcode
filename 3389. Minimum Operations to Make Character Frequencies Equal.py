class Solution:
    def makeStringGood(self, s: str) -> int:
        d = Counter(s)
        mx = max(d.values())

        @cache
        def f(target, i):
            if i < 0:
                return 0
            x = d[chr(ord('a') + i - 1)]
            ans = f(target, i-1) + min(abs(target-x), x)
            if i-2 >= 0 and x < target:
                y = d[chr(ord('a') + i - 2)]
                # 1. dec y to 0 with op3, add to x
                cost = y + max(0, target-(x+y))
                # 2. dec y to target with op3, add to x
                if y > target:
                    dec = y - target
                    cost = min(cost, dec + max(0, target-(x+dec)))
                ans = min(ans, f(target, i-2) + cost)
            return ans

        ans = inf
        for t in range(mx+1):
            ans = min(ans, f(t, 26))

        return ans
