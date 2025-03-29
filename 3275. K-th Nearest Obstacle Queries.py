class Solution:
    def resultsArray(self, queries: List[List[int]], k: int) -> List[int]:
        q = []
        ans = []
        for x, y in queries:
            d = abs(x) + abs(y)
            heappush(q, -d)
            if len(q) < k:
                ans.append(-1)
            else:
                if len(q) > k:
                    heappop(q)
                ans.append(-q[0])
        return ans
