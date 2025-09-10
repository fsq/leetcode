class Solution:
    def maxAmount(self, initialCurrency: str, pairs1: List[List[str]], rates1: List[float], pairs2: List[List[str]], rates2: List[float]) -> float:
        e = defaultdict(dict)
        for (x, y), r in zip(pairs1, rates1):
            e[x][y] = r
            e[y][x] = 1/r
        for x in e.keys():
            e[x][x+"1"] = 1
        for (x, y), r in zip(pairs2, rates2):
            e[x+"1"][y+"1"] = r
            e[y+"1"][x+"1"] = 1/r
        ans = defaultdict(lambda: -1)
        ans[initialCurrency] = 1
        q = [[-1, initialCurrency]]
        while len(q):
            w, x = heappop(q)
            w = -w
            if w < ans[x]:
                continue
            for y, r in e[x].items():
                wr = w * r
                if wr > ans[y]:
                    ans[y] = wr
                    heappush(q, [-wr, y])
        return ans[initialCurrency+"1"]
