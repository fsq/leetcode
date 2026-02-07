class Solution:
    def lenOfVDiagonal(self, a: List[List[int]]) -> int:
        n, m = len(a), len(a[0])
        f0 = [[[0]*4 for _ in range(m)] for _ in range(n)]
        f1 = [[[-inf]*4 for _ in range(m)] for _ in range(n)]
        for i in range(n):
            for j in range(m):
                if a[i][j] != 1:
                    f0[i][j] = [1] * 4
                    if i>0 and j>0:
                        if a[i-1][j-1]==2-a[i][j]:
                            f0[i][j][0] = f0[i-1][j-1][0] + 1
                            f1[i][j][0] = f1[i-1][j-1][0] + 1
                        elif a[i-1][j-1]==1 and a[i][j]==2:
                            f1[i][j][0] = 2
                    if i>0 and j+1<m:
                        if a[i-1][j+1]==2-a[i][j]: 
                            f0[i][j][1] = f0[i-1][j+1][1] + 1
                            f1[i][j][1] = f1[i-1][j+1][1] + 1
                        elif a[i-1][j+1]==1 and a[i][j]==2:
                            f1[i][j][1] = 2
                else:
                    for k in range(4):
                        f1[i][j][k] = 1
        ans = 0
        for i in reversed(range(n)):
            for j in range(m):
                if a[i][j] != 1:
                    if i+1<n and j+1<m:
                        if a[i+1][j+1]==2-a[i][j]:
                            f0[i][j][2] = f0[i+1][j+1][2] + 1
                            f1[i][j][2] = f1[i+1][j+1][2] + 1
                        elif a[i+1][j+1]==1 and a[i][j]==2:
                            f1[i][j][2] = 2
                    if i+1<n and j>0:
                        if a[i+1][j-1]==2-a[i][j]: 
                            f0[i][j][3] = f0[i+1][j-1][3] + 1
                            f1[i][j][3] = f1[i+1][j-1][3] + 1
                        elif a[i+1][j-1]==1 and a[i][j]==2:
                            f1[i][j][3] = 2
                    for k in range(4):
                        ans = max(ans, f1[i][j][k] + f0[i][j][(k+3)%4] - 1)
                else:
                    ans = max(ans, 1)

        return ans
