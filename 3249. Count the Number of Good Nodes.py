class Solution:
    def countGoodNodes(self, edges: List[List[int]]) -> int:
        n = len(edges) + 1
        e = [[] for _ in range(n)]
        for x, y in edges:
            e[x].append(y)
            e[y].append(x)
        ans = 0
        def dfs(x, pre=-1):
            nonlocal ans
            same = True
            sz = -1
            tot = 1
            for y in e[x]:
                if y != pre:
                    sub = dfs(y, x)
                    tot += sub
                    if same:
                        if sz==-1:
                            sz = sub
                        elif sz != sub:
                            same = False
            if same:
                ans += 1
            return tot

        dfs(0)
        return ans