isp = []

class Solution:

    def calc(self):
        isp[:] = [True] * 10000
        isp[0] = isp[1] = False
        ps = []
        for x in range(2, len(isp)):
            if isp[x]:
                ps.append(x)
            for p in ps:
                if x * p >= len(isp):
                    break
                isp[x*p] = False
                if x % p == 0:
                    break

    def minOperations(self, n: int, m: int) -> int:
        if len(isp) == 0:
            self.calc()

        if isp[n] or isp[m]:
            return -1
        q = list()
        q.append([n, n])
        cost = defaultdict(lambda: inf)
        cost[n] = n

        while len(q):
            c, x = heappop(q)
            if x == m:
                return c
            if c > cost[x]:
                continue

            x = list(map(int, str(x)))
            for i in range(len(x)):
                df = []
                if x[i]>=1: df.append(-1)
                if x[i]<9: df.append(1)
                for d in df:
                    y = x[:]
                    y[i] += d
                    y = int(''.join(map(str, y)))
                    if not isp[y] and c+y<cost[y]:
                        cost[y] = c + y
                        heappush(q, [c+y, y])
        return -1
                

