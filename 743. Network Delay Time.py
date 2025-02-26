class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        e = []
        for i in range(n+1):
            e.append([])
        for pr in times:
            e[pr[0]].append([pr[1], pr[2]])

        dis = [math.inf] * (n+1)
        dis[k] = 0
        q = []
        vis = set()
        # dijkstra
        heappush(q, [0, k])
        while len(q) > 0:
            d, x = heappop(q)
            if x in vis:
                continue
            for y, w in e[x]:
                if (y not in vis) and (d + w < dis[y]):
                    dis[y] = d + w
                    heappush(q, [d+w, y])
        time = max(dis[1:])
        return time if time != math.inf else -1