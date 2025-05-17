class Solution:
    def countKReducibleNumbers(self, s: str, k: int) -> int:
        M = 10**9 + 7
        ans = 0

        @cache
        def dp(l, one, boundary):
            if l == len(s):
                return 1
            ans = 0
            if len(s)-l-1 >= one:
                ans = dp(l+1, one, boundary and s[l]=='0')
            if one>0 and not (boundary and s[l]=='0'):
                ans = (ans + dp(l+1, one-1, boundary and s[l]=='1')) % M
            return ans

        def k_reducible(x):
            for _ in range(k-1):
                x = x.bit_count()
            return x == 1

        for x in range(1, len(s) + 1):
            if k_reducible(x):
                ans = (ans + dp(0, x, True)) % M

        ans = (ans - (1 if k_reducible(s.count('1')) else 0)) % M
        return ans
        