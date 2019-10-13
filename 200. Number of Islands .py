class Solution:
    
    def numIslands(self, a: List[List[str]]) -> int:
        if not len(a): return 0
        n, m, ans = len(a), len(a[0]), 0
        
        def dfs(a: List[List[str]], x:int, y:int):
            a[x][y] = "0"
            for dx,dy in [[-1,0],[1,0],[0,1],[0,-1]]:
                    tx, ty = x+dx, y+dy
                    if tx>=0 and tx<n and ty>=0 and ty<m and a[tx][ty]=="1":
                        dfs(a, tx, ty)
        
        for i in range(n):
            for j in range(m):
                if a[i][j]=="1":
                    ans += 1
                    dfs(a, i, j)
        
        return ans
                    