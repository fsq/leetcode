class Solution:
    def maxSum(self, a: List[List[int]], limits: List[int], k: int) -> int:
        q = []
        for i, b in enumerate(a):
            b.sort(reverse=True)
            if limits[i] > 0:
                heappush(q, (-b[0], i, 0))

        taken = 0
        ans = 0
        while taken<k and len(q):
            _, i, cnt = heappop(q)
            ans += a[i][cnt]
            cnt += 1
            taken += 1
            if cnt < limits[i]:
                heappush(q, (-a[i][cnt], i, cnt))
        return ans



    def maxSumDP(self, a: List[List[int]], limits: List[int], k: int) -> int:
        n, m = len(a), len(a[0])
        for b in a:
            b.sort(reverse=True)
        f = [-inf] * (k+1)
        f[0] = 0
        for i in range(n):
            g = f[:]
            for j in range(1, min(k, (i+1)*m)+1):
                acc = 0
                for c in range(1, min(m, j, limits[i])+1):
                    if a[i][c-1]==0:
                        break
                    acc += a[i][c-1]
                    g[j] = max(g[j], f[j-c] + acc)
            f = g[:]
        return max(f)
        
