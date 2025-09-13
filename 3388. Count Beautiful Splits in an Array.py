class Solution:
    def beautifulSplits(self, a: List[int]) -> int:
        n = len(a)
        f = [[0]*(n+1) for _ in range(n+1)]
        for i in reversed(range(n)):
            for j in range(i+1, n):
                if a[i]==a[j]:
                    f[i][j] = f[i+1][j+1] + 1
        ans = 0
        for i in range(1, n):
            for j in range(i+1, n):
                if (f[0][i]>=i and i+i-1<j) or f[i][j]>=j-i:
                    ans += 1
        return ans

