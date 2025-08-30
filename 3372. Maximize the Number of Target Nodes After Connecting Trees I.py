class Solution:
    def maxTargetNodes(self, edges1: List[List[int]], edges2: List[List[int]], k: int) -> List[int]:
        n = len(edges1) + 1
        m = len(edges2) + 1
        e1 = [[] for _ in range(n)]
        e2 = [[] for _ in range(m)]
        for u, v in edges1:
            e1[u].append(v)
            e1[v].append(u)
        for u, v in edges2:
            e2[u].append(v)
            e2[v].append(u)

        def dfs(e, x, k, fa=-1):
            if k < 0:
                return 0
            if k == 0:
                return 1
            ans = 1
            for y in e[x]:
                if y != fa:
                    ans += dfs(e, y, k-1, x)
            return ans

        d1 = [dfs(e1, i, k) for i in range(n)]
        d2 = [dfs(e2, i, k-1) for i in range(m)]
        mx = max(d2)
        d1 = list(map(lambda x: x + mx, d1))
        return d1
