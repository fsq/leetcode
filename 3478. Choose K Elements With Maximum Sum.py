class Solution:
    def findMaxSum(self, num: List[int], b: List[int], k: int) -> List[int]:
        a = []
        for i, v in enumerate(num):
            a.append((num[i], i))
        a.sort()
        ans = {}
        q = []
        tot = 0
        for i, (v, ind) in enumerate(a):
            if not (ind>0 and v==a[i-1][0]):
                ans[v] = tot
            heappush(q, b[ind])
            tot += b[ind]
            if len(q) > k:
                tot -= heappop(q)
        return [ans[v] for v in num]
