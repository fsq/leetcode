class Solution:
    def minimumIncrements(self, nums: List[int], target: List[int]) -> int:
        len_m = 1 << len(target)
        f = [inf] * len_m
        f[0] = 0

        for x in nums:
            g = f[:]
            for m in range(1, len_m):
                for mp in range(len_m):
                    if (m & mp) != mp or f[mp] == inf:
                        continue
                    new = [target[i] for i in range(len(target)) if (m ^ mp) >> i & 1]
                    l = lcm(*new)
                    new_x = int(ceil(x/l)) * l
                    g[m] = min(g[m], f[mp] + new_x - x)
            f = g
        return f[-1]
