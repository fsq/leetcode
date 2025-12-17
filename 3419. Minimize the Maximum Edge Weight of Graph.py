import queue

class Solution:
    def minMaxWeight(self, n: int, edges: List[List[int]], threshold: int) -> int:
        e = [[] for _ in range(n)]
        for y, x, w in edges:
            e[x].append((y, w))

        d = [inf] * n
        vis = set()
        pq = [(0, 0)]
        while len(pq):
            w, x = heappop(pq)
            if x in vis or w > d[x]:
                continue
            d[x] = w
            vis.add(x)
            for y, w in e[x]:
                if max(d[x], w) < d[y]:
                    d[y] = max(d[x], w)
                    heappush(pq, (d[y], y))

        if len(vis) != n:
            return -1
        return max(d)
