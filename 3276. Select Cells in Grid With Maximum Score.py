class Solution:
    def maxScore(self, a: List[List[int]]) -> int:
        f = defaultdict(int)
        mi = defaultdict(set)
        for i in range(len(a)):
            for x in a[i]:
                mi[x].add(i)
        f[0] = 0
        for val in mi.keys():
            g = defaultdict(int)
            for cur_m, tot in f.items():
                for i in mi[val]:
                    if not ((1<<i) & cur_m):
                        g[cur_m | (1<<i)] = max(g[cur_m | (1<<i)], tot + val)
            for gm, gv in g.items():
                f[gm] = max(f[gm], gv)
        return max(f.values())

