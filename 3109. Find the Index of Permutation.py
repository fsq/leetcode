class Solution:
    def getPermutationIndex(self, a: List[int]) -> int:
        n = len(a)
        s = [0] * (n+1)
        ans = 0

        def lowbit(x):
            return x & (-x)

        def inc(x):
            while x < len(s):
                s[x] += 1
                x += lowbit(x)
        
        def count(x):
            ans = 0
            while x > 0:
                ans += s[x]
                x -= lowbit(x)
            return ans

        fac = [1]
        for i in range(1, n+1):
            fac.append(fac[-1] * i % int(1e9+7))
        for i, x in enumerate(reversed(a)):
            inc(x)
            ans = (ans + fac[i] * count(x-1)) % int(1e9 + 7)

        return ans