class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
        n, m = len(edges1)+1, len(edges2)+1
        e1 = [[] for _ in range(n)]
        e2 = [[] for _ in range(m)]
        for x, y in edges1:
            e1[x].append(y)
            e1[y].append(x)
        for x, y in edges2:
            e2[x].append(y)
            e2[y].append(x)

        def color(e, f, x, c, pre=-1):
            f[x] = c
            for y in e[x]:
                if y != pre:
                    color(e, f, y, c^1, x)
        
        f = [0] * n
        g = [0] * m
        color(e1, f, 0, 0)
        color(e2, g, 0, 0)

        tot1 = [0, 0]
        tot1[0] = f.count(0)
        tot1[1] = n - tot1[0]

        mx = g.count(0)
        mx = max(mx, m-mx)

        return [tot1[f[x]]+mx for x in range(n)]

    # DP
    # def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]]) -> List[int]:
    #     n, m = len(edges1)+1, len(edges2)+1
    #     e1 = [[] for _ in range(n)]
    #     e2 = [[] for _ in range(m)]
    #     for x, y in edges1:
    #         e1[x].append(y)
    #         e1[y].append(x)
    #     for x, y in edges2:
    #         e2[x].append(y)
    #         e2[y].append(x)
        
    #     f = [[0, 0] for _ in range(n)]
    #     g = [[0, 0] for _ in range(m)]

    #     def dfs1(e, f, x, pre=-1):
    #         f[x][0] = 1
    #         for y in e[x]:
    #             if y != pre:
    #                 dfs1(e, f, y, x)
    #                 f[x][0] += f[y][1]
    #                 f[x][1] += f[y][0]
        
    #     def dfs2(e, f, x, pre=-1):
    #         for y in e[x]:
    #             if y != pre:
    #                 even, odd = f[x][1]-f[y][0], f[x][0]-f[y][1]
    #                 f[y][0] += even
    #                 f[y][1] += odd
    #                 dfs2(e, f, y, x)

    #     def dp(e, f):
    #         dfs1(e, f, 0)
    #         dfs2(e, f, 0)

    #     dp(e1, f)
    #     dp(e2, g)

    #     mx = max([odd for _, odd in g])
    #     return [even+mx for even, _ in f]       
