class Solution:
    def criticalConnections(self, n: int, a: List[List[int]]) -> List[List[int]]:
        d, e, ans = [0] * n, [[] for i in range(n)], []
        for p in a:
            e[p[0]].append(p[1])
            e[p[1]].append(p[0])
            
        def dfs(x: int, fa: int, dp: int):
            lo = d[x] = dp
            for y in e[x]:
                if y != fa:
                    if not d[y]:
                        s = dfs(y, x, dp+1)
                        if s > dp:
                            ans.append([x, y])
                        lo = min(lo, s)
                    else:
                        lo = min(lo, d[y])
            return lo
            
        for i in range(n):
            if not d[i]:
                dfs(i, -1, 1)
        return ans
        