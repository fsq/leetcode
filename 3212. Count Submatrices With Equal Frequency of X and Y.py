class Solution:
    def numberOfSubmatrices(self, a: List[List[str]]) -> int:
        m = len(a[0])
        x = [0]*m
        y = [0]*m
        ans = 0
        for row in a:
            cx = cy = 0
            for i in range(m):
                if row[i] == 'X':
                    cx += 1
                elif row[i] == 'Y':
                    cy += 1
                x[i] += cx
                y[i] += cy
                if x[i]==y[i] and x[i]>0:
                    ans += 1
        return ans