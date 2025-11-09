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

        l, r = 1, len(s)
        while l < r:
            m = (l + r) >> 1
            if change(m) <= budget:
                r = m
            else:
                l = m + 1
        return l
