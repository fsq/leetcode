class Solution:
    def timeTaken(self, edges: List[List[int]]) -> List[int]:
        e = defaultdict(list)
        n = len(edges) + 1
        for x, y in edges:
            e[x].append([y, 1 if y & 1 else 2])
            e[y].append([x, 1 if x & 1 else 2])
        f = [0] * n  # longest path in subtree
        g = [0] * n  # longest path from x->fa->any other node
        ans = [0] * n

        def MaxSubtree(x, fa=-1):
            for y, d in e[x]:
                if y != fa:
                    f[x] = max(f[x], d + MaxSubtree(y, x))
            return f[x]
        MaxSubtree(0)

        def MaxParentPath(x, fa=-1):
            ans[x] = max(f[x], g[x])
            m1, m2 = 0, 0
            for y, d in e[x]:
                if y != fa:
                    l = f[y] + d # from x to subtree of y
                    if l >= m1:
                        m1, m2 = l, m1
                    elif l > m2:
                        m2 = l
            for y, d in e[x]:
                if y != fa:
                    l = m2 if f[y]+d==m1 else m1
                    g[y] = max(l, g[x]) + (1 if x & 1 else 2)
                    MaxParentPath(y, x)
        MaxParentPath(0)
        
        return ans