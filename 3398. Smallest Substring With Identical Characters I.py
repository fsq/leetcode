class Solution:

    def minLength(self, s: str, budget: int) -> int:
        a = [int(c) for c in s]
        gs = []
        for x, it in groupby(a):
            gs.append(len(list(it)))

        def change(l):
            if l == 1:
                zero_one = sum([int(x != i % 2) for i, x in enumerate(a)])
                one_zero = sum([int(x != (i % 2 ^ 1)) for i, x in enumerate(a)])
                return min(zero_one, one_zero)
            return sum([g // (l + 1) for g in gs])

        l, r = 1, 1000
        while l < r:
            m = (l + r) >> 1
            if change(m) <= budget:
                r = m
            else:
                l = m + 1
        return l


    def minLength_binary_dp(self, s: str, budget: int) -> int:
        def change(s, l):
            f = [[inf, inf] for _ in range(len(s))]
            for i in range(len(s)):
                for cur in [0, 1]:
                    changed = 0
                    for j in range(i, i-l, -1):
                        if j < 0:
                            break
                        if s[j] != chr(cur + ord('0')):
                            changed += 1
                        if j == 0:
                            f[i][cur] = min(f[i][cur], changed)
                        else:
                            f[i][cur] = min(f[i][cur], changed + f[j-1][cur ^ 1])
            return min(f[-1])
            
        l, r = 1, 1000
        while l < r:
            m = (l + r) >> 1
            if change(s, m) <= budget:
                r = m
            else:
                l = m + 1
        return l

        
