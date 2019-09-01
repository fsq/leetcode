class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        vis, p = [False] * (n+1), []
        for i in range(2, n+1):
            if not vis[i]: p.append(i)
            for j in range(len(p)):
                if p[j]*i <= n:
                    vis[p[j] * i] = True
                    if i%p[j]==0:
                        break
                else:
                    break
        ans = 1
        M = 1000000007
        for i in range(1, len(p)+1):
            ans = ans * i % M
        for i in range(1, n-len(p)+1):
            ans = ans * i % M
        return ans