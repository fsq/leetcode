class Solution:
    def maximalSquare(self, a: List[List[str]]) -> int:
        if a==[]: return 0
        ans, n, m = 0, len(a), len(a[0])
        f = [[0]*m for _ in range(n)]
        
        for i in range(n):
            for j in range(m):
                if a[i][j]=="1":
                    f[i][j] = f[i-1][j] if i>0 else 0
                    f[i][j] = min(f[i][j], f[i][j-1] if j>0 else 0)
                    f[i][j] = min(f[i][j], f[i-1][j-1] if i>0 and j>0 else 0)
                    f[i][j] += 1
                    ans = max(ans, f[i][j])
        
        return ans*ans
        